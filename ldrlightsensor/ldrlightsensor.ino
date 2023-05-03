const int LDRpin = A0;
const int LEDpin = 2;
int ldr;


void setup() {
   pinMode(LEDpin, OUTPUT);  
}

void loop() {
 
  ldr = analogRead(LDRpin);
  if (ldr <200)
  {
    digitalWrite(LEDpin, HIGH);
  }
  else
  {
    digitalWrite(LEDpin, LOW);
  }
  
  delay(500);
}
