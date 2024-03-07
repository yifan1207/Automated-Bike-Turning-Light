// Define the pins for the VRM, the Bluetooth modules, the LED display boards, the audio player, the switches, and the battery  
#define trigPin 6 // Trigger Pin for the ultrasonic sensor 
#define echoPin 7 // Echo Pin for the ultrasonic sensor 
#define buttonPin 8 // Button Pin for the three-positioned swithc
#define VRMPin A0 // VRM Pin for the voltage regulator module
#define BT1TX 10 // Bluetooth 1 TX Pin for the turning  system
#define BT1RX 11 // Bluetooth 1 RX Pin for the turning  system
#define BT2TX 12 // Bluetooth 2 TX Pin for the display board
#define BT2RX 13 // Bluetooth 2 RX Pin for the display board
#define LED1R 2 // LED 1 Red Pin for the first LED display board
#define LED1G 3 // LED 1 Green Pin for the first LED display board
#define LED1B 4 // LED 1 Blue Pin for the first LED display board
#define LED2R 5 // LED 2 Red Pin for the second LED display board
#define LED2G 6 // LED 2 Green Pin for the second LED display board
#define LED2B 7 // LED 2 Blue Pin for the second LED display board
#define LED3R 8 // LED 3 Red Pin for the third LED display board
#define LED3G 9 // LED 3 Green Pin for the third LED display board
#define LED3B 10 // LED 3 Blue Pin for the third LED display board
#define LED4R 11 // LED 4 Red Pin for the fourth LED display board
#define LED4G 12 // LED 4 Green Pin for the fourth LED display board
#define LED4B 13 // LED 4 Blue Pin for the fourth LED display board
#define AP1TX 14 // Audio Player 1 TX Pin for the sound function
#define AP1RX 15 // Audio Player 1 RX Pin for the sound function
#define BATPin A1 // Battery Pin for the 12V battery

// Define the constants for the maximum and minimum range, the threshold angle, the number of cycles, the delay value, and the RGB values for the display colors
#define maximumRange 200 // Maximum range needed for the ultrasonic sensor
#define minimumRange 0 // Minimum range needed for the ultrasonic sensor
#define thresholdAngle 15 // Threshold angle for the VRM to detect turn
#define numCycles 10 // Number of cycles for the irregular flash pattern
#define delayValue 1000000 // Delay value for the sound function
#define redValue 255 // Red value for the display color
#define greenValue 255 // Green value for the display color
#define blueValue 255 // Blue value for the display color

// Define the variables for the duration, distance, turn state, previous turn state, and button state
long duration, distance; // Duration and distance for the ultrasonic sensor
int turnState, prevTurnState; // Turn state and previous turn state for the turning detection system
int buttonState; // Button state for the three-positioned switch

// Define the serial objects for the Bluetooth modules and the audio player
SoftwareSerial BT1(BT1TX, BT1RX); // Bluetooth 1 for the turning detection system
SoftwareSerial BT2(BT2TX, BT2RX); // Bluetooth 2 for the display board
SoftwareSerial AP1(AP1TX, AP1RX); // Audio Player 1 for the sound function

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  BT1.begin(9600);
  BT2.begin(9600);
  AP1.begin(9600);

  // Initialize the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(VRMPin, INPUT);
  pinMode(LED1R, OUTPUT);
  pinMode(LED1G, OUTPUT);
  pinMode(LED1B, OUTPUT);
  pinMode(LED2R, OUTPUT);
  pinMode(LED2G, OUTPUT);
  pinMode(LED2B, OUTPUT);
  pinMode(LED3R, OUTPUT);
  pinMode(LED3G, OUTPUT);
  pinMode(LED3B, OUTPUT);
  pinMode(LED4R, OUTPUT);
  pinMode(LED4G, OUTPUT);
  pinMode(LED4B, OUTPUT);
  pinMode(BATPin, INPUT);

  // Initialize the Bluetooth connection
  BT1.write("AT+NAME=Turning Detection System\r\n"); // Set the name of the Bluetooth 1
  BT1.write("AT+ROLE=0\r\n"); // Set the role of the Bluetooth 1 as slave
  BT2.write("AT+NAME=Display Board\r\n"); // Set the name of the Bluetooth 2
  BT2.write("AT+ROLE=1\r\n"); // Set the role of the Bluetooth 2 as master
  BT2.write("AT+CMODE=0\r\n"); // Set the connection mode of the Bluetooth 2 as fixed address
  BT2.write("AT+BIND=Turning Detection System\r\n"); // Bind the Bluetooth 2 to the Bluetooth 1
  BT2.write("AT+INIT\r\n"); // Initialize the Bluetooth 2
  BT2.write("AT+INQ\r\n"); // Inquire the Bluetooth 2
  BT2.write("AT+PAIR=Turning Detection System,20\r\n"); // Pair the Bluetooth 2 with the Bluetooth 1
  BT2.write("AT+LINK=Turning Detection System\r\n"); // Link the Bluetooth 2 with the Bluetooth 1
}

void loop() {
  // Read the distance from the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;

  // Read the button state from the three-positioned switch
  buttonState = digitalRead(buttonPin);

  // If the button state is not zero, set the turn state to the corresponding value
  if (buttonState == 1) {
    turnState = 1; // Left turn
  }
  else if (buttonState == 2) {
    turnState = 2; // Forward
  }
  else if (buttonState == 3) {
    turnState = 3; // Right turn
  }
  // Else, read the resistance from the VRM and set the turn state accordingly
  else {
    int resistance = analogRead(VRMPin); // Read the resistance from 0 to 1023
    resistance = map(resistance, 0, 1023, 0, 1000); // Map the resistance to a range of
