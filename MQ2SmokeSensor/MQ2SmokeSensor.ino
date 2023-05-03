// YOUSEF IBRAHIM GOMAA MAHMOUD - 320210207 - SECTION 10
// ------------------------------
// MQ2 Smoke Sensor
const int Analog = A0;
const int Digital = 6;
int READING;
// LEDs
const int LEDpin1 = 2; // GREEN
const int LEDpin2 = 3; // RED
//
const int BUZZ = 4; // BUZZER

void setup() {
  pinMode(Digital, OUTPUT);
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(Analog, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LEDpin1,LOW);
  digitalWrite(LEDpin2,LOW);
  digitalWrite(BUZZ,LOW);
  // INPUT DATA
  READING = analogRead(Analog);
  
  Serial.print("Reading: ");
  Serial.print(READING);
  Serial.print("\n");
  // LED LIGHT UP
  if (READING>=300)
  {
    digitalWrite(LEDpin2, HIGH);
    tone(BUZZ,1000);
    delay(500);
    noTone(BUZZ);
    delay(500);
  }
  else 
  {
    digitalWrite(LEDpin1, HIGH);
    delay(500);
  }
delay(500);  
}
