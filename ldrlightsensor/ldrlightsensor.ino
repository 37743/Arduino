const int LDRpin = A0;
const int LEDpin = 2;
int ldr;

void setup() {
   pinMode(LEDpin, OUTPUT);  
   pinMode(LDRpin, INPUT);
   Serial.begin(9600);
}

void loop() {
  ldr = analogRead(LDRpin);
  Serial.print(ldr);
  Serial.print("\n");
  if (ldr<100)
  {
    digitalWrite(LEDpin, HIGH);
  }
  else
  {
    digitalWrite(LEDpin, LOW);
  }
  delay(500);
}
