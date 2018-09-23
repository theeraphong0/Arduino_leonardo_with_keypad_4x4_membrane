#include "Keyboard.h"
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Keyboard.releaseAll();
  //while (!Serial) {
  //  ; // wait for serial port to connect. Needed for native USB port only
  //}
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey) {
    Serial.println(customKey);
    switch (customKey) {
      case '1':
        Keyboard.println("push key 1");
        break;
      case '2':
        Keyboard.println("push key 2");
        break;
      case '3':
        Keyboard.println("push key 3");
        break;
      case '4':
        Keyboard.println("push key 4");
        break;
      case '5':
        Keyboard.println("push key 5");
        break;
      case '6':
        Keyboard.println("push key 6");
        break;
      case '7':
        Keyboard.println("push key 7");
        break;
      case '8':
        Keyboard.println("push key 8");
        break;
      case '9':
        Keyboard.println("push key 9");
        break;
      case '0':
        Keyboard.println("push key 0");
        break;
      case 'A':
        Keyboard.println("push key A");
        break;
      case 'B':
        Keyboard.println("push key B");
        break;
      case 'C':
        Keyboard.println("push key C");
        break;
      case 'D':
        Keyboard.println("push key D");
        break;
      case '*':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('r');
        Keyboard.releaseAll();
        delay(50);
        Keyboard.println("cmd");
        break;
      case '#':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('r');
        Keyboard.releaseAll();
        delay(50);
        Keyboard.println("cmd");
        delay(50);
        Keyboard.println("ping 8.8.8.8");
        break;
      default:
        break;
    }
  }
}
