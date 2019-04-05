// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

//Breadboard LED Pins
const int BUTTON = 5;
const int DOWN = 6;
const int LEFT = 9;
const int RIGHT = 10;
const int UP = 11;


int switch_state = 0;
int x_axis = 0;
int y_axis = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  switch_state = digitalRead(SW_pin);
  x_axis = analogRead(X_pin);
  y_axis = analogRead(Y_pin);

  switch_state == 0 ? setLEDButton(255) : setLEDButton(0);

  // 0 = left, 1000 = right
  if (x_axis <= 450)
  {
    setLEDLeft(255);
    setLEDRight(0);
  }
  else if (x_axis >= 550)
  {
    setLEDLeft(0);
    setLEDRight(255);
  }
  else
  {
    setLEDLeft(0);
    setLEDRight(0);
  }

  // 0 = up, 1000 = down
  if (y_axis <= 450)
  {
    setLEDUp(255);
    setLEDDown(0);
  }
  else if (y_axis >= 550)
  {
    setLEDUp(0);
    setLEDDown(255);
  }
  else
  {
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
