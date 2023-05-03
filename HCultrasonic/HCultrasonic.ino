// YOUSEF IBRAHIM GOMAA MAHMOUD - 320210207 - SECTION 10
// ------------------------------
// Ultrasonic Sensor
const int ECHO = A0;
const int TRIG = 6;
// LEDs
const int LEDpin1 = 2; // GREEN
const int LEDpin2 = 3; // RED
const int LEDpin3 = 4;
const int BUZZ = 5; // BUZZER

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LEDpin1,LOW);
  digitalWrite(LEDpin2,LOW);
  digitalWrite(LEDpin3,LOW);
  digitalWrite(BUZZ,LOW);
  // INPUT DATA
  digitalWrite(TRIG,LOW);
  delay(5);
  digitalWrite(TRIG,HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);
  long TIME = pulseIn(ECHO,HIGH);
  // SPEED = DISTANCE/TIME
  Serial.print("Distance: ");
  Serial.print(DISTANCE);
  Serial.print(" cm\n");
  // LED LIGHT UP
  if(DISTANCE<40)
  {
    if (DISTANCE>=30) digitalWrite(LEDpin1,HIGH);
    else // DISTANCE < 30
    {
        if (DISTANCE>=20) digitalWrite(LEDpin2,HIGH);
        else // DISTANCE < 20
        {
          if (DISTANCE>=10) digitalWrite(LEDpin3,HIGH);
          else
          {
            tone(BUZZ,1000);
            delay(500);
            noTone(BUZZ);
            delay(500);
          }
        }
    }
  }
delay(500);  
}