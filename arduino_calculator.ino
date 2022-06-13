#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool LastButtonOperator = false;
int blocks = 0;
int ButtonZero = 22;
int ButtonOne = 23;
int ButtonTwo = 24;
int ButtonPlus = 38; // branco
int ButtonEqual = 39; // Verde
int ButtonMinus = 40; // roxo
int ButtonClear = 53; // laranja
int num[15];

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ButtonZero, INPUT_PULLUP);
  pinMode(ButtonOne, INPUT_PULLUP);
  pinMode(ButtonTwo, INPUT_PULLUP);
  pinMode(ButtonPlus, INPUT_PULLUP);
  pinMode(ButtonEqual, INPUT_PULLUP);
  pinMode(ButtonMinus, INPUT_PULLUP);
  pinMode(ButtonClear, INPUT_PULLUP);
}
 
void loop() {
  // Números
  if (blocks != 0 && LastButtonOperator == false) {
    if (digitalRead(ButtonZero) == LOW) {
      delay(50);
      if (digitalRead(ButtonZero) == HIGH) {
        delay(50);
        LastButtonOperator = false;
        num[blocks] = 0;
        blocks = blocks + 1;
        lcd.print(0);
      }
    }
  }

  if (digitalRead(ButtonOne) == LOW) {
    delay(50);
    if (digitalRead(ButtonOne) == HIGH) {
      delay(50);
      LastButtonOperator = false;
      num[blocks] = 1;
      blocks = blocks + 1;
      lcd.print(1);
    }
  }

  if (digitalRead(ButtonTwo) == LOW) {
    delay(50);
    if (digitalRead(ButtonTwo) == HIGH) {
      delay(50);
      LastButtonOperator = false;
      num[blocks] = 2;
      blocks = blocks + 1;
      lcd.print(2);
    }
  }


  // Operadores
  if (blocks != 0) {
    if (digitalRead(ButtonPlus) == LOW) {
      delay(50);
      if (digitalRead(ButtonPlus) == HIGH) {
        delay(50);
        if (LastButtonOperator == false) {
          LastButtonOperator = true;
          num[blocks] = "+";
          blocks = blocks + 1;
          lcd.print("+");
        }
        else {
          num[blocks - 1] = "+";
          lcd.setCursor(blocks - 1, 0);
          lcd.print("+");
        }
      }
    }
  }

  if (blocks != 0) {
    if (digitalRead(ButtonPlus) == LOW) {
      delay(50);
      if (digitalRead(ButtonPlus) == HIGH) {
        delay(50);
        if (LastButtonOperator == false) {
          LastButtonOperator = true;
          num[blocks] = "-";
          blocks = blocks + 1;
          lcd.print("-");
        }
        else {
          num[blocks - 1] = "-";
          lcd.setCursor(blocks - 1, 0);
          lcd.print("-");
        }
      }
    }
  }


  // Limpar a tela
  if (digitalRead(ButtonClear) == LOW) {
    delay(50);
    if (digitalRead(ButtonClear) == HIGH) {
      delay(50);
      for(int i = 0; i < blocks; i++) {
        Serial.println(num[i]);
      }
      blocks = 0;
      lcd.clear();
    }
  }
}
