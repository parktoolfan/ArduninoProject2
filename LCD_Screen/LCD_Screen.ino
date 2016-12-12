#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

ParallaxLCD lcd(4,2,16);

void setup() {
  lcd.setup();
  delay(500);
  lcd.backLightOn();
  lcd.empty();

  char string1[] ="Testing...";
  lcd.at(0,0,string1);
  lcd.at(1,0,"1 2 3");
  delay(2000);

  char outPut[] = "I hope this works...";
  toPrint(outPut);

  char outPut1[] = "It works!";
  toPrint(outPut1);
}

  void toPrint(char output[]) {
   lcd.empty();
   lcd.at(0,0, output);
   delay(5000);
  }
  
 

void loop() {
}
