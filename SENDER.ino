#include <SoftwareSerial.h> 
 
// Pin10为RX，接HC05的TXD
// Pin11为TX，接HC05的RXD
//定义接口
//const int M1 = 2; //define ENA Pin

const int KEY1 = 2;//
const int KEY2 = 3;//


SoftwareSerial BT(12, 13); 
char Indicator = 0;
char val;
char KEY_state = 0;
char prior = 0;//优先级标志位 如果为0则开启上位机控制1 使用按键控制

void Get_Command()
{
    int buttonState1 = digitalRead(KEY1);
    if(buttonState1 == HIGH)
    {
      buttonState1 = 1;
    } 
    else
    {
      buttonState1 = 0;
    }
    int buttonState2 = digitalRead(KEY2);
    if(buttonState2 == HIGH)
    {
      buttonState2 = 1;
    } 
    else
    {
      buttonState2 = 0;
    }
    if((buttonState1 == 1)&&(buttonState2 == 1))
    {
      Indicator = 0;
      prior = 0;
    }
    if((buttonState1 == 0)&&(buttonState2 == 1))
    {
      Indicator = 1;
      prior = 1;
    }
    if((buttonState1 == 1)&&(buttonState2 == 0))
    {
      Indicator = 2;
      prior = 1;
    }  
}
 
void setup() {
  Serial.begin(9600); 
  Serial.println("BT is ready!");
  // HC-05默认，38400
  BT.begin(38400);

  pinMode(KEY1,INPUT_PULLUP );
  pinMode(KEY2,INPUT_PULLUP );
  
  
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 

  
}
void Get_Position()
{
  //读取传感器数值
  int Sensor_Resistence = 0;//可变电阻值，最大1023
  int Sensor_Resistence_Raw = analogRead(A0);//限位传感器
  //判断传感器状态
  Sensor_Resistence = Sensor_Resistence_Raw;//将模拟量转换为对应的速度值   转换量程之后为 0-256

  Serial.print("Sensor_Resistence_Raw");
  Serial.println(Sensor_Resistence_Raw,DEC);
  if(prior == 0)
  {
    if((Sensor_Resistence >= 450)&&(Sensor_Resistence <= 550))
    {
      Indicator = 0;
    }
    else if(Sensor_Resistence <450)
    {
      Indicator = 2;
    }
    else if(Sensor_Resistence >550)
    {
      Indicator = 1;
    }
  }
}
void loop() {
  delay(200);
  Get_Command();//获得按键的值 此函数放前面
  Get_Position();//获取当前车把方向  此函数放后面
  BT.print(Indicator,DEC);//蓝牙发送数据到终端机
  Serial.println(Indicator,DEC);//蓝牙发送数据到终端机
  
//  if (Serial.available()) {
//    val = Serial.read();
//    BT.print(val);
//  }
// 
//  if (BT.available()) {
//    val = BT.read();
//    Serial.print(val);
//  }
}
