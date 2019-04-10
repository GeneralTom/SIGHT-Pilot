#define analogPin A0 // potentiometer wiper (middle terminal) connected to analog pin 3
                      // outside leads to ground and +5V
#define LED0 8
#define LED1 9
#define LED2 10
#define LED3 11

#define ENABLE 5
#define PWM1_OUT 3
#define PWM2_OUT 5
    
uint16_t analogIn = 0;     // variable to store the value read
uint8_t fanSpeed = 0;     // variable to calculate the fan speed

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM1_OUT, OUTPUT);
  pinMode(PWM2_OUT, OUTPUT);
  pinMode(LED0, OUTPUT);  // Green LED
  pinMode(LED1, OUTPUT);  // Blue LED
  pinMode(LED2, OUTPUT);  // Yellow LED
  pinMode(LED3, OUTPUT);  // Red LED
  Serial.begin(9600);

  digitalWrite(PWM2_OUT, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  setFan();
  setLED();
}

void setLED(){
  if((analogIn <= 255) && (analogIn > 0)){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
  else if((analogIn <= 511) && (analogIn >= 256)){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
  else if((analogIn <= 767) && (analogIn >= 512)){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  else if((analogIn <= 1023) && (analogIn >= 768)){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else{
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
}

void setFan(){
  analogIn = analogRead(analogPin);   // read the input pin
  //Serial.println(analogIn);           // debug value
  fanSpeed = (0.25 * analogIn);
  Serial.println(fanSpeed);
  analogWrite(PWM1_OUT, fanSpeed);
}
