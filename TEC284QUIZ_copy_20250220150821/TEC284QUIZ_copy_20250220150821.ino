int redPin = 12;
int bluePin = 11;
int greenPin = 10;
int redButt = 7;
int greenButt = 6;
int blueButt = 5;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int lastRedButtState = LOW;
int currentRedButtState = LOW;
int lastGreenButtState = LOW;
int currentGreenButtState = LOW;
int lastBlueButtState = LOW;
int currentBlueButtState = LOW;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redButt, INPUT);
  pinMode(greenButt, INPUT);
  pinMode(blueButt, INPUT);
}

void loop() {
  currentRedButtState = digitalRead(redButt);
  currentGreenButtState = digitalRead(greenButt);
  currentBlueButtState = digitalRead(blueButt);

  // If red button is pressed (HIGH to LOW transition)
  if (currentRedButtState == LOW && lastRedButtState == HIGH) {
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
  }

  // If green button is pressed (HIGH to LOW transition)
  if (currentGreenButtState == LOW && lastGreenButtState == HIGH) {
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
  }

  // If blue button is pressed (HIGH to LOW transition)
  if (currentBlueButtState == LOW && lastBlueButtState == HIGH) {
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
  }

  // Update the LED with the selected color values
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Save the current button states for the next loop
  lastRedButtState = currentRedButtState;
  lastGreenButtState = currentGreenButtState;
  lastBlueButtState = currentBlueButtState;
}
