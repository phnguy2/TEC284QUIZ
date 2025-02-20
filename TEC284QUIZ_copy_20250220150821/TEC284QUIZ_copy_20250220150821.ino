// Define pin numbers for RGB LED and buttons
int redPin = 12;   // Red LED pin
int bluePin = 11;  // Blue LED pin
int greenPin = 10; // Green LED pin
int redButt = 7;   // Red button pin
int greenButt = 6; // Green button pin
int blueButt = 5;  // Blue button pin

// Variables to store LED brightness levels
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

// Variables to track button states
int lastRedButtState = LOW;
int currentRedButtState = LOW;
int lastGreenButtState = LOW;
int currentGreenButtState = LOW;
int lastBlueButtState = LOW;
int currentBlueButtState = LOW;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Set button pins as INPUT
  pinMode(redButt, INPUT);
  pinMode(greenButt, INPUT);
  pinMode(blueButt, INPUT);
}

void loop() {
  // Read the current state of each button
  currentRedButtState = digitalRead(redButt);
  currentGreenButtState = digitalRead(greenButt);
  currentBlueButtState = digitalRead(blueButt);

  // Reset color values
  redValue = 0;
  greenValue = 0;
  blueValue = 0;

  // Check if any button has been pressed
  checkRedButton();
  checkGreenButton();
  checkBlueButton();

  // Update the RGB LED color based on button presses
  updateLED();

  // Store the current button state for the next iteration
  lastRedButtState = currentRedButtState;
  lastGreenButtState = currentGreenButtState;
  lastBlueButtState = currentBlueButtState;
}

// Function to check if the red button is pressed
void checkRedButton() {
  if (currentRedButtState == LOW) {
    redValue = 255;   // Set red component
  }
}

// Function to check if the green button is pressed
void checkGreenButton() {
  if (currentGreenButtState == LOW) {
    greenValue = 255; // Set green component
  }
}

// Function to check if the blue button is pressed
void checkBlueButton() {
  if (currentBlueButtState == LOW) {
    blueValue = 255; // Set blue component
  }
}

// Function to update the RGB LED color
void updateLED() {
  analogWrite(redPin, redValue);   // Adjust red brightness
  analogWrite(greenPin, greenValue); // Adjust green brightness
  analogWrite(bluePin, blueValue); // Adjust blue brightness
}
