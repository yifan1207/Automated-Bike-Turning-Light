// Define the pins for the LED display boards
#define LED1R 2 // LED 1 Red Pin for the first LED  board
#define LED1G 3 // LED 1 Green Pin for the first LED  board
#define LED1B 4 // LED 1 Blue Pin for the first LED  board
#define LED2R 5 // LED 2 Red Pin for the second LED display board
#define LED2G 6 // LED 2 Green Pin for the second LED display board
#define LED2B 7 // LED 2 Blue Pin for the second LED display board
#define LED3R 8 // LED 3 Red Pin for the third LED display board
#define LED3G 9 // LED 3 Green Pin for the third LED display board
#define LED3B 10 // LED 3 Blue Pin for the third LED display board
#define LED4R 11 // LED 4 Red Pin for the fourth LED display board
#define LED4G 12 // LED 4 Green Pin for the fourth LED display board
#define LED4B 13 // LED 4 Blue Pin for the fourth LED display board

// Define the constants for the number of cycles, the delay value, and the RGB values for the display colors
#define numCycles 10 // Number of cycles for the irregular flash pattern
#define delayValue 100 // Delay value for the irregular flash pattern
#define redValue 255 // Red value for the display color
#define greenValue 255 // Green value for the display color
#define blueValue 255 // Blue value for the display color

// Define the variable for the turn state
int turnState; // Turn state for the turning detection system

// Define the array for the arrow icons
byte arrowIcons[3][16] = {
  {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // Left arrow
   0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00111111, 0b01111111, 0b11111111},
  {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // Forward arrow
   0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // Right arrow
   0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111}
};

void setup() {
  // Initialize the pin modes
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
}

void loop() {
  // Read the turn state from the turning detection system
  turnState = BT1.read(); // Assuming BT1 is the Bluetooth module for the turning detection system
  
  // Call the display function with the turn state as the argument
  display(turnState);
}

void display(int turnState) {
  // Select the appropriate arrow icon from the array
  byte* arrowIcon = arrowIcons[turnState - 1]; // turnState is 1, 2, or 3
  
  // Repeat the irregular flash pattern for a specified number of cycles
  for (int i = 0; i < numCycles; i++) {
    // Turn off all the LEDs by setting the RGB values to zero
    analogWrite(LED1R, 0);
    analogWrite(LED1G, 0);
    analogWrite(LED1B, 0);
    analogWrite(LED2R, 0);
    analogWrite(LED2G, 0);
    analogWrite(LED2B, 0);
    analogWrite(LED3R, 0);
    analogWrite(LED3G, 0);
    analogWrite(LED3B, 0);
    analogWrite(LED4R, 0);
    analogWrite(LED4G, 0);
    analogWrite(LED4B, 0);
    
    // Delay for a random time between 50 and 200 milliseconds
    delay(random(50, 200));
    
    // Turn on the LEDs that overlap with the arrow icon by setting the RGB values to the desired color
    for (int j = 0; j < 16; j++) {
      // Check if the j-th bit of the arrow icon is 1
      if (arrowIcon[j] & 0b00000001) {
        // Set the RGB values of the corresponding LED to the desired color
        analogWrite(LED1R, redValue);
        analogWrite(LED1G, greenValue);
        analogWrite(LED1B, blueValue);
      }
      if (arrowIcon[j] & 0b00000010) {
        analogWrite(LED2R, redValue);
        analogWrite(LED2G, greenValue);
        analogWrite(LED2B, blueValue);
      }
      if (arrowIcon[j] & 0b00000100) {
        analogWrite(LED3R, redValue);
        analogWrite(LED3G, greenValue);
        analogWrite(LED3B, blueValue);
      }
      if (arrowIcon[j] & 0b00001000) {
        analogWrite(LED4R, redValue);
        analogWrite(LED4G, greenValue);
        analogWrite(LED4B, blueValue);
      }
    }
    
    // Delay for another random time between 50 and 200 milliseconds
    delay(random(50, 200));
  }
}
