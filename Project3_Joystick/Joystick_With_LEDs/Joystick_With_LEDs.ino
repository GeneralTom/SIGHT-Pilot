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
  switch_state == 0 ? setLEDButton(255) : setLEDButton(0);

  /**
   * This first section of if statements controls the LEFT and RIGHT LEDs.
   *
   * After testing the joystick for directions, it output the following:
   * 0 = left, 1000 = right
   */
  if (x_axis <= 450)
  {
    // Lights up the LEFT LED
    setLEDLeft(255);
    setLEDRight(0);
  }
  else if (x_axis >= 550)
  {
    // Lights up the RIGHT LED
    setLEDLeft(0);
    setLEDRight(255);
  }
  else
  {    
    // If the stick is centered, both the LEFT and RIGHT LEDs will be off
    setLEDLeft(0);
    setLEDRight(0);
  }

  /**
   * This section of if statements controls the UP and DOWN LEDs.
   *
   * After testing the joystick for directions, it output the following:
   * 0 = up, 1000 = down
   */
  if (y_axis <= 450)
  {
    // Lights up the top LED
    setLEDUp(255);
    setLEDDown(0);
  }
  else if (y_axis >= 550)
  {
    // Lights up the bottom LED
    setLEDUp(0);
    setLEDDown(255);
  }
  else
  {
    // The stick is centered, so both LEDs are off.
    setLEDUp(0);
    setLEDDown(0);
  }
  
  delay(100);
}

void setLEDUp(int brightness)
{
  analogWrite(UP, brightness);
}

void setLEDDown(int brightness)
{
  analogWrite(DOWN, brightness);
}

void setLEDLeft(int brightness)
{
  analogWrite(LEFT, brightness);
}

void setLEDRight(int brightness)
{
  analogWrite(RIGHT, brightness);
}

void setLEDButton(int brightness)
{
  analogWrite(BUTTON, brightness);
}
