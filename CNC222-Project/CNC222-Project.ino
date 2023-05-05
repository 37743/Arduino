// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207
// ------------------
#include <Keypad.h>

// INITIALIZATION
// ------------------
const int LEDpin = 12;
const int SPCpin = 13;

String INP = "";
String MORSEinp = "";
// ---------------------v-------v-------v-------v-------v-------v-------v-------v-------v-------v
//                      0       1       2       3       4       5       6       7       8       9
String MORSEnum[] = {"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

// KEYPAD
char keys[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Attached ROWS/COL to Arduino UNO's pins no. #
byte pin_rows[4] = {10, 9, 8, 7};
byte pin_cols[3] = {6, 5, 4};

void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(SPCpin, OUTPUT);
  Serial.begin(9600);
  Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_cols, 4, 3);
  char KEY;
  int MAX = 0; // Max no. of key inputs at a time
  do // Build input
  {
    KEY = keypad.getKey();
    if (KEY)
    {
      INP += KEY;
      MAX++;
      Serial.print(KEY);
      if (KEY == '*') {INP = ""; MAX=0; Serial.print("\n");}    
    }
  } while((KEY != '#') && (MAX < 16));
  INP.remove(INP.length()-1,1);     
  Serial.print("\n------\n");
  Serial.println(INP);
}

void loop() {
  digitalWrite(LEDpin, LOW);
  digitalWrite(SPCpin, LOW);
  for (int i=0; i<INP.length(); i++)
  {
    MORSEinp.concat(MORSEnum[(int)INP[i]-(int)'0']);
    MORSEinp.concat(' ');
  }  
  for (int j=0; j<MORSEinp.length(); j++)
  {
    delay(500);
    if (MORSEinp[j]==' ')
    {
      digitalWrite(SPCpin, HIGH);
      delay(800);
      digitalWrite(SPCpin, LOW);
    }
    else if(MORSEinp[j]=='.')
    {
      digitalWrite(LEDpin, HIGH);
      delay(1600);
      digitalWrite(LEDpin, LOW);                  
    }
    else if(MORSEinp[j]=='-')
    {
      digitalWrite(LEDpin, HIGH);
      delay(2400);
      digitalWrite(LEDpin, LOW);
    }
    Serial.print(MORSEinp[j]);
  };
  Serial.print("END\n");
  for (int i=0; i<2; i++) // Blink SPACE LED to indicate end of sequence
  {
    digitalWrite(SPCpin, HIGH);
    delay(800);
    digitalWrite(SPCpin, LOW);
    delay(800);
  }
  while (true) delay(5000);
}
