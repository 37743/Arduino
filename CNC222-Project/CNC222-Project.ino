// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207
// ------------------ 
#include <Keypad.h>
#include <avr/io.h>
#define __AVR_ATmega32U4__
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

extern "C" unsigned char LEDSetUP(unsigned char);
extern "C" void LEDon(void);
extern "C" void LEDoff(void);
extern "C" void SPCLEDon(void);
extern "C" void SPCLEDoff(void);

// Attached ROWS/COL to Arduino UNO's pins no. #
byte pin_rows[4] = {10, 9, 8, 7};
byte pin_cols[3] = {6, 5, 4};

void setup() {
  // pinMode(LEDpin, OUTPUT);
  // pinMode(SPCpin, OUTPUT);
  Serial.begin(115200);
  LEDSetUP(5);
  LEDSetUP(6);
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
  LEDoff();
  SPCLEDoff();
  for (int i=0; i<INP.length(); i++)
  {
    MORSEinp.concat(MORSEnum[(int)INP[i]-(int)'0']);
    MORSEinp.concat(' ');
  }  
  for (int j=0; j<MORSEinp.length(); j++)
  {
    delay(800);
    if (MORSEinp[j]==' ')
    {
      SPCLEDon();
      delay(800);
      SPCLEDoff();
    }
    else if(MORSEinp[j]=='.')
    {
      LEDon();
      delay(800);
      LEDoff();                  
    }
    else if(MORSEinp[j]=='-')
    {
      LEDon();
      delay(1600);
      LEDoff();
    }
    Serial.print(MORSEinp[j]);
  };
  Serial.print("END\n");
  for (int i=0; i<3; i++) // Blink SPACE LED to indicate end of sequence
  {
    SPCLEDon();
    delay(400);
    SPCLEDoff();
    delay(400);
  }
  while(true) delay(5000);
}
