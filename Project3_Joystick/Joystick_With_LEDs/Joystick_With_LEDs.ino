// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

// Breadboard LED Pins
const int BUTTON = 5;
const int DOWN = 6;
const int LEFT = 9;
const int RIGHT = 10;
const int UP = 11;

// Constants
const int LED_ON = 255;
const int LED_OFF = 0;

// Initial values
int switch_state = 0;
int x_axis = 0;
int y_axis = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // Read information from the joystick
  switch_state = digitalRead(SW_pin);
  x_axis = analogRead(X_pin);
  y_axis = analogRead(Y_pin);

  /**
   * This line checks for if the joystick's built in button was pressed
   *
   * In this case, the switch uses negative logic.
   * So, the LED will light up if the joystick sends back a zero.
   */
  switch_state == 0 ? setLED(BUTTON, LED_ON) : setLED(BUTTON, LED_OFF);

  /**
   * This first section of if statements controls the LEFT and RIGHT LEDs.
   *
   * After testing the joystick for directions, it output the following:
   * 0 = left, 1000 = right
   */
  if (x_axis <= 450) {
    // Lights up the LEFT LED
    setLED(LEFT, LED_ON);
    setLED(RIGHT, LED_OFF);
  }
  else if (x_axis >= 550) {
    // Lights up the RIGHT LED
    setLED(LEFT, LED_OFF);
    setLED(RIGHT, LED_ON);
  }
  else {    
    // If the stick is centered, both the LEFT and RIGHT LEDs will be off
    setLED(LEFT, LED_OFF);
    setLED(RIGHT, LED_OFF);
  }

  /**
   * This section of if statements controls the UP and DOWN LEDs.
   *
   * After testing the joystick for directions, it output the following:
   * 0 = up, 1000 = down
   */
  if (y_axis <= 450) {
    // Lights up the UP LED 
    setLED(UP, LED_ON);
    setLED(DOWN, LED_OFF);
  }
  else if (y_axis >= 550) {
    // Lights up the DOWN LED
    setLED(UP, LED_OFF);
    setLED(DOWN, LED_ON);
  }
  else {
    // The stick is centered, so both LEDs are off.
    setLED(UP, LED_OFF);
    setLED(DOWN, LED_OFF);
  }
  
  delay(100);
}

/**
 * The function below is used for adjusting the brightness for each of the LEDs
 */

void setLED(const int& direction, const int& brightness) {
  analogWrite(direction, brightness);
}
