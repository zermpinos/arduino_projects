#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
void setup(){
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}
void loop(){
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(20);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says: ");
      lcd.setCursor(0,1 );
      switch(reply){
        case 0:
        lcd.print("It is certain!");
        break;
        case 1:
        lcd.print("No doubt!");
        break;
        case 2:
        lcd.print("Yes, definetly!");
        break;
        case 3:
        lcd.print("As I see, yes!");
        break;
        case 4:
        lcd.print("Looks good!");
        break;
        case 5:
        lcd.print("Ask again!");
        break;
        case 6:
        lcd.print("Cannot say!");
        break;
        case 7:
        lcd.print("Focus and ask!");
        break;
        case 8:
        lcd.print("Cannot predict!");
        break;
        case 9:
        lcd.print("Not good!");
        break;
        case 10:
        lcd.print("Very doubtful!");
        break;
        case 11:
        lcd.print("Unlikely!");
        break;
        case 12:
        lcd.print("Be careful!");
        break;
        case 13:
        lcd.print("No!");
        break;
        case 14:
        lcd.print("Yes!");
        break;
        case 15:
        lcd.print("Maybe!");
        break;
        case 16:
        lcd.print("All points->NO!");
        break;
        case 17:
        lcd.print("All points->YES!");
        break;
        case 18:
        lcd.print("Definetly not!");
        break;
        case 19:
        lcd.print("Go ahead!");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}