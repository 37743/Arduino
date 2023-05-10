// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207
// ------------------

// INITIALIZATION
// ------------------
const int LDRpin1 = A0;
const int LDRpin2 = A1;
int LDRreading1;
int LDRreading2;

int SPCcount=0;
String OUT = "";
String MORSEout = "";
// ---------------------v-------v-------v-------v-------v-------v-------v-------v-------v-------v
//                      0       1       2       3       4       5       6       7       8       9
String MORSEnum[] = {"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

void setup() {
  pinMode(LDRpin1, INPUT);
  pinMode(LDRpin2, INPUT);   
  Serial.begin(115200);
}

void loop() {
  while(true) // Build MORSEout until LEDs stop blinking.
  {
    LDRreading1 = analogRead(LDRpin1);
    LDRreading2 = analogRead(LDRpin2);
    // Serial.println(LDRreading1);
    // Serial.println(LDRreading2);
    delay(50);
    if (LDRreading2 < 35)
    {
      if (LDRreading1 >= 30)
      {
        delay(850);
        LDRreading1 = analogRead(LDRpin1);
        if (LDRreading1 < 30)
        {
          MORSEout += '.';
          Serial.print("LDR Reading: ");
          Serial.print(LDRreading1);
          Serial.print(" | INPUT: .\n");
          SPCcount = 0;
          continue;
        }
        if (LDRreading1 >= 30)
        {
          MORSEout += '-';
          Serial.print("LDR Reading: ");
          Serial.print(LDRreading1);
          Serial.print(" | INPUT: -\n");
          SPCcount = 0;
        }
        delay(750);
      }
    }
    else
    {
      MORSEout += ' ';
      SPCcount++;
      Serial.print("SPC LDR Reading: ");
      Serial.print(LDRreading2);
      Serial.print(" | INPUT: (SPACE)\n");
      delay(850);
      if (SPCcount>2) break; // Break after 3 spaces (LEDs stop blinking)
    }
  }
  Serial.println(MORSEout);
  String TEMP="";
  for (int i=0; i<MORSEout.length(); i++) // Generate OUT based on the results of MORSEout
  {
    if (MORSEout[i]!=' ') TEMP += MORSEout[i]; // Fill until a space is found
    else {
      if (TEMP != "")
      {
        for (int j=0; j<sizeof(MORSEnum)/sizeof(MORSEnum[0]); j++)
          {
            if (TEMP==MORSEnum[j]) {OUT += j;} // Look for entry in the array of Morse codes (MORSEnum)
          }
          TEMP=""; // Clear TEMP
      }
    }
  }
  Serial.println("OUTPUT: "+OUT);
  while(true) {delay(5000);}
}
