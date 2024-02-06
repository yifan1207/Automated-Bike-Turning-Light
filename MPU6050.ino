
//MPU1-UNO
//VCC-VCC
//GND-GND
//SCL-A5
//SDA-A4
//INT-2

#include <Kalman.h>
#include <Wire.h>
#include <Math.h>

float fRad2Deg1 = 57.295779513f; //将弧度转为角度的乘数
const int MPU1 = 0x69; //MPU1-6050的I2C地址
const int nValCnt1 = 7; //一次读取寄存器的数量

const int nCalibTimes1 = 1000; //校准时读数的次数
int calibData1[nValCnt1]; //校准数据

unsigned long nLastTime1 = 0; //上一次读数的时间
float fLastRoll1 = 0.0f; //上一次滤波得到的Roll角
float fLastPitch1 = 0.0f; //上一次滤波得到的Pitch角
Kalman kalmanRoll1; //Roll角滤波器
Kalman kalmanPitch1; //Pitch角滤波器

void setup() {
  Serial.begin(9600); //初始串口，指定波特率
  Wire.begin(); //初始化Wire库
  WriteMPU1Reg1(0x6B, 0); //启动MPU16050设备

  Calibration1(); //执行校准
  nLastTime1 = micros(); //记录当前时间
}

void loop() {
  int readouts1[nValCnt1];
  ReadAccGyr1(readouts1); //读出测量值
  
  float realVals1[7];
  Rectify1(readouts1, realVals1); //根据校准的偏移量进行纠正

  //计算加速度向量的模长，均以g为单位
  float fNorm1 = sqrt(realVals1[0] * realVals1[0] + realVals1[1] * realVals1[1] + realVals1[2] * realVals1[2]);
  float fRoll1 = GetRoll1(realVals1, fNorm1); //计算Roll角
  if (realVals1[1] > 0) {
    fRoll1 = -fRoll1;
  }
  float fPitch1 = GetPitch1(realVals1, fNorm1); //计算Pitch角
  if (realVals1[0] < 0) {
    fPitch1 = -fPitch1;
  }

  //计算两次测量的时间间隔dt1，以秒为单位
  unsigned long nCurTime1 = micros();
  float dt1 = (double)(nCurTime1 - nLastTime1) / 1000000.0;
  //对Roll角和Pitch角进行卡尔曼滤波
  float fNewRoll1 = kalmanRoll1.getAngle(fRoll1, realVals1[4], dt1);
  float fNewPitch1 = kalmanPitch1.getAngle(fPitch1, realVals1[5], dt1);
  //跟据滤波值计算角度速
  float fRoll1Rate1 = (fNewRoll1 - fLastRoll1) / dt1;
  float fPitch1Rate1 = (fNewPitch1 - fLastPitch1) / dt1;
 
 //更新Roll角和Pitch角
  fLastRoll1 = fNewRoll1;
  fLastPitch1 = fNewPitch1;
  //更新本次测的时间
  nLastTime1 = nCurTime1;

  //向串口打印输出Roll角和Pitch角，运行时在Arduino的串口监视器中查看
  Serial.print("Roll:");
  Serial.print(fNewRoll1); Serial.print('(');
  Serial.print(fRoll1Rate1); Serial.print("),\tPitch:");
  Serial.print(fNewPitch1); Serial.print('(');
  Serial.print(fPitch1Rate1); Serial.print(")\n");
  delay(10);
}

//向MPU16050写入一个字节的数据
//指定寄存器地址与一个字节的值
void WriteMPU1Reg1(int nReg1, unsigned char nVal1) {
  Wire.beginTransmission(MPU1);
  Wire.write(nReg1);
  Wire.write(nVal1);
  Wire.endTransmission(true);
}

//从MPU16050读出一个字节的数据
//指定寄存器地址，返回读出的值
unsigned char ReadMPU1Reg1(int nReg1) {
  Wire.beginTransmission(MPU1);
  Wire.write(nReg1);
  Wire.requestFrom(MPU1, 1, true);
  Wire.endTransmission(true);
  return Wire.read();
}

//从MPU16050读出加速度计三个分量、温度和三个角速度计
//保存在指定的数组中
void ReadAccGyr1(int *pVals1) {
  Wire.beginTransmission(MPU1);
  Wire.write(0x3B);
  Wire.requestFrom(MPU1, nValCnt1 * 2, true);
  Wire.endTransmission(true);
  for (long i = 0; i < nValCnt1; ++i) {
    pVals1[i] = Wire.read() << 8 | Wire.read();
  }
}

//对大量读数进行统计，校准平均偏移量
void Calibration1()
{
  float valSums1[7] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0};
  //先求和
  for (int i = 0; i < nCalibTimes1; ++i) {
    int MPU1Vals1[nValCnt1];
    ReadAccGyr1(MPU1Vals1);
    for (int j = 0; j < nValCnt1; ++j) {
      valSums1[j] += MPU1Vals1[j];
    }
  }
  //再求平均
  for (int i = 0; i < nValCnt1; ++i) {
    calibData1[i] = int(valSums1[i] / nCalibTimes1);
  }
  calibData1[2] += 16384; //设芯片Z轴竖直向下，设定静态工作点。
}

//算得Roll角。算法见文档。
float GetRoll1(float *prealVals1, float fNorm1) {
  float fNorm1XZ1 = sqrt(prealVals1[0] * prealVals1[0] + prealVals1[2] * prealVals1[2]);
  float fCos1 = fNorm1XZ1 / fNorm1;
  return acos(fCos1) * fRad2Deg1;
}

//算得Pitch角。算法见文档。
float GetPitch1(float *prealVals1, float fNorm1) {
  float fNorm1YZ1 = sqrt(prealVals1[1] * prealVals1[1] + prealVals1[2] * prealVals1[2]);
  float fCos1 = fNorm1YZ1 / fNorm1;
  return acos(fCos1) * fRad2Deg1;
}

//对读数进行纠正，消除偏移，并转换为物理量。公式见文档。
void Rectify1(int *pReadout1, float *prealVals1) {
  for (int i = 0; i < 3; ++i) {
    prealVals1[i] = (float)(pReadout1[i] - calibData1[i]) / 16384.0f;
  }
  prealVals1[3] = pReadout1[3] / 340.0f + 36.53;
  for (int i = 4; i < 7; ++i) {
    prealVals1[i] = (float)(pReadout1[i] - calibData1[i]) / 131.0f;
  }
}
