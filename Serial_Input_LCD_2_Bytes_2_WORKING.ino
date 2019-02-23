#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 13, 1, 2, 3, 4);

bool readConfigNum = true;
byte configNum = 0;
byte settingNum = 0;
bool isEnabled = false;


void setup() {
  Serial.begin(9600);  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.setCursor(6, 0);
  lcd.print("ONYX");
  lcd.setCursor(2, 1);
  lcd.print("ROHAWKS 3419");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    if (readConfigNum) {
      configNum = Serial.read();
      readConfigNum = false;
    }
    else {
      settingNum = Serial.read();
      readConfigNum = true;

      //CONFIGURATIONS AND SETTINGS
      if (configNum == 1) {
        if (settingNum == 1 || settingNum == 2 || settingNum == 3) {
          isEnabled = false;
          lcd.setCursor(0, 0);
          lcd.print("      ONYX     ");
          lcd.setCursor(0, 1);
          lcd.print("  ROHAWKS 3419  ");
          if (settingNum == 1) {
            //set to purple
          }
          else if (settingNum == 2) {
            //set to red
          }
          else {
            //set to blue
          }
        }
        else {
          isEnabled = true;
          lcd.setCursor(0, 0);
          lcd.print("  B:F ONYX L:F  ");
          lcd.setCursor(0, 1);
          lcd.print(" STATESTATESTA ");
          //set to either orange or yellow
        }
      }
      if (isEnabled) {
        if (configNum == 2) {
          lcd.setCursor(0, 1);
          if (settingNum == 1) lcd.print("   INIT BALL    ");
          else if (settingNum == 2) lcd.print("   INIT HATCH   ");
          else if (settingNum == 3) lcd.print(" HATCH SC CARGO ");
          else if (settingNum == 4) lcd.print(" HATCH SC ROCK  ");
          else if (settingNum == 5) lcd.print(" WAITING 2 LOAD ");
          else if (settingNum == 6) lcd.print(" LOADING HATCH  ");
          else if (settingNum == 7) lcd.print(" HATCH PRESCORE ");
          else if (settingNum == 8) lcd.print("  LOADING BALL  ");
          else if (settingNum == 9) lcd.print(" BALL PRESCORE  ");
          else if (settingNum == 10) lcd.print(" BALL FRONT SC  ");
          else if (settingNum == 11) lcd.print("  BALL BACK SC  ");
          else if (settingNum == 12) lcd.print("    DEFENSE     ");
          else if (settingNum == 13) lcd.print("     CLIMB      ");
          else if (settingNum == 14) lcd.print("    DEFAULT     ");
          else lcd.print("    UNKNOWN     ");
        }
        else if (configNum == 3) {
          if (settingNum == 1) {
            lcd.setCursor(0, 0);
            lcd.write(' ');
            lcd.setCursor(15, 0);
            lcd.write(' ');
          }
          else if (settingNum == 2) {
            lcd.setCursor(0, 0);
            lcd.write(byte(127));
            lcd.setCursor(15, 0);
            lcd.write(' ');
          }
          else if (settingNum == 3) {
            lcd.setCursor(0, 0);
            lcd.write(' ');
            lcd.setCursor(15, 0);
            lcd.write(byte(126));
          }
          else {
            lcd.setCursor(0, 0);
            lcd.write(byte(127));
            lcd.setCursor(15, 0);
            lcd.write(byte(126));
          }
        }
        else if (configNum == 5) {
          lcd.setCursor(4, 0);
          if (settingNum == 1) {
            lcd.write('T');
          }
          else {
            lcd.write('F');
          }
        }
        else if (configNum == 6) {
          lcd.setCursor(13, 0 );
          if (settingNum == 1) {
            lcd.write('T');
          }
          else {
            lcd.write('F');
          }
        }
        else if (configNum == 4) {
          //add slider code 
        }
      }
    }
  }
}
