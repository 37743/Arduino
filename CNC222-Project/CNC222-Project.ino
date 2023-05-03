#define each(item, array, length) \
(typeof(*(array)) *p = (array), (item) = *p; p < &((array)[length]); p++, (item) = *p)

const int LDRpin = A0;
const int LEDpin = 2;
const int SPACEpin = 3;
char* INP[] = {"HELLO"};

char* MINP[] = {".",".",".","."," "," ","."," "," ",".","-",".","."," "," ",".","-",".","."," "," ","-","-","-"};
void setup() {
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LEDpin, LOW);
  for each(ch, MINP, sizeof(MINP)/sizeof(MINP[0]))
  {
      delay(500);
        if (ch==" ")
        {
          digitalWrite(SPACEpin, HIGH);
          delay(400);
          digitalWrite(SPACEpin, LOW);
          Serial.print("SPACE\n");         
        }
        else if(ch==".")
        {
          digitalWrite(LEDpin, HIGH);
          delay(800);
          digitalWrite(LEDpin, LOW);                  
          Serial.print("DOT\n");
        }
        else if(ch=="-")
        {
          digitalWrite(LEDpin, HIGH);
          delay(1200);
          digitalWrite(LEDpin, LOW);
          Serial.print("HYPHEN\n");
        }
  };
  Serial.print("END");
  delay(5000);
}
