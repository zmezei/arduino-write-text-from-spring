#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte separator = 255;
int numberOfLetters;
void setup() {
  Serial.begin(9600);
}

void loop() {
  numberOfLetters = Serial.available() - 1;
  if (numberOfLetters > 0) {
    char message[numberOfLetters];
    for (int i = 0; i < numberOfLetters; i++) {
      message[i] = Serial.read();
    }
    lcd.begin(16,2);
    lcd.print(message);
  }
}
