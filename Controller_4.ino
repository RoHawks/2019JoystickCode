#include <Joystick.h>
int digitalButtonPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};
bool whichButtonsPressed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
int xAxis_ = 0;
//Joystick_ Joystick; 

void setup() {
  for(int i = 0; i < 20; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Joystick.begin();
}

void loop() {  

  //Panel Buttons
  if(digitalRead(A4) == LOW) {
    Joystick.pressButton(18);
    for(int i = 0; i < 20; i++) {
      if(digitalRead(digitalButtonPins[i]) == LOW) {
        whichButtonsPressed[i] = true;
      } else {
        whichButtonsPressed[i] = false;
      }
    }
  
    delay(20);

    //Press Buttons 1 to 14
    for(int i = 0; i < 18; i++) {
      if(whichButtonsPressed[i] == true) {
        Joystick.pressButton(i);
      } else {
        Joystick.releaseButton(i);
      }
    }
  }

  //Ball Buttons
  else {
    Joystick.releaseButton(18);
    for(int i = 0; i < 20; i++) {
      if(digitalRead(digitalButtonPins[i]) == LOW) {
        whichButtonsPressed[i] = true;
      } else {
        whichButtonsPressed[i] = false;
      }
    }
  
    delay(20);

    //First 5 buttons
    for(int i = 0; i < 5; i++) {
      if(whichButtonsPressed[i] == true) {
        Joystick.pressButton(i); 
      } else {
        Joystick.releaseButton(i);
      }
    }

    //change HAS_SCORED to button 21
    if(whichButtonsPressed[5] == true) {
      Joystick.pressButton(20);
    }
    else {
      Joystick.releaseButton(20);
    }

    //Buttons 7-14
    for(int i = 6; i < 14; i++) {
      if(whichButtonsPressed[i] == true) {
        Joystick.pressButton(i);
      }
      else {
        Joystick.releaseButton(i);
      }
    }

    
    //Change SCORE_BACKWARDS to 22, SCORE to 23, HAS_LOADED to 24, and LOAD to 25
    for(int i = 14; i < 19; i++) {
      if(whichButtonsPressed[i] == true) {
        Joystick.pressButton(i+7);
      }
      else {
        Joystick.releaseButton(i+7);
      }
    }                
  }

  xAxis_ = analogRead(digitalButtonPins[19]);
  xAxis_ = map(xAxis_, 0, 1023, -127, 127);
  Joystick.setXAxis(xAxis_);

}
