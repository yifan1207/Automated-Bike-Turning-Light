// Define the analog input pin for VRM
#define VRM_PIN A0

// Define the turn 
#define LEFT 1
#define RIGHT 2
#define FORWARD 0

// Define the resistance thresholds for left and right turns
#define LEFT_THRESHOLD 550
#define RIGHT_THRESHOLD 450

// Declare a variable to store the turn state
int turn_state = FORWARD;

void setup() {
  // Initialize serial communications
  Serial.begin(9600);
}

void loop() {
  // Read the resistance value from VRM
  int resistance = analogRead(VRM_PIN);

  // Map the resistance value to a turn state
  if (resistance > LEFT_THRESHOLD) {
    turn_state = LEFT;
  } else if (resistance < RIGHT_THRESHOLD) {
    turn_state = RIGHT;
  } else {
    turn_state = FORWARD;
  }

  // Send the turn state to the display board via serial communication
  Serial.write(turn_state);

  // Wait for a short delay
  delay(100);
}
