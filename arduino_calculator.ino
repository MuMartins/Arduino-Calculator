#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool LastButtonOperator = false;
int position = 0;
int blocks = 0;
const int ButtonZero = 22;
const int ButtonOne = 23;
const int ButtonTwo = 24;
const int ButtonThree = 25;
const int ButtonFour = 26;
const int ButtonPlus = 38; // branco
const int ButtonEqual = 39; // Verde
const int ButtonMinus = 40; // roxo
const int ButtonClear = 53; // laranja
String num[15];

void logical_number(String button_number) {
  LastButtonOperator = false;
  num[blocks] = button_number;
  blocks += 1;
  position += 1;
  lcd.print(button_number);
}

void logical_operator(String button_operator) {
  if (LastButtonOperator == false) {
    LastButtonOperator = true;
    num[blocks] = button_operator;
    blocks += 1;
    position += 1;
    lcd.print(button_operator);
  }
  else {
    num[blocks - 1] = button_operator;
    lcd.setCursor(position - 1, 0);
    lcd.print(button_operator);
  }
}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ButtonZero, INPUT_PULLUP);
  pinMode(ButtonOne, INPUT_PULLUP);
  pinMode(ButtonTwo, INPUT_PULLUP);
  pinMode(ButtonThree, INPUT_PULLUP);
  pinMode(ButtonFour, INPUT_PULLUP);
  pinMode(ButtonPlus, INPUT_PULLUP);
  pinMode(ButtonEqual, INPUT_PULLUP);
  pinMode(ButtonMinus, INPUT_PULLUP);
  pinMode(ButtonClear, INPUT_PULLUP);
}
 
void loop() {
  // Números
  if (position != 0 && LastButtonOperator == false) {
    if (digitalRead(ButtonZero) == LOW) {
      delay(50);
      if (digitalRead(ButtonZero) == HIGH) {
        delay(50);
        logical_number("0");
      }
    }
  }

  if (digitalRead(ButtonOne) == LOW) {
    delay(50);
    if (digitalRead(ButtonOne) == HIGH) {
      delay(50);
      logical_number("1");
    }
  }

  if (digitalRead(ButtonTwo) == LOW) {
    delay(50);
    if (digitalRead(ButtonTwo) == HIGH) {
      delay(50);
      logical_number("2");
    }
  }

  if (digitalRead(ButtonThree) == LOW) {
    delay(50);
    if (digitalRead(ButtonThree) == HIGH) {
      delay(50);
      logical_number("3");
    }
  }

  if (digitalRead(ButtonFour) == LOW) {
    delay(50);
    if (digitalRead(ButtonFour) == HIGH) {
      delay(50);
      logical_number("4");
    }
  }


  // Operadores
  if (position != 0) {
    if (digitalRead(ButtonEqual) == LOW) {
      delay(50);
      if (digitalRead(ButtonEqual) == HIGH) {
        delay(50);
        for(int i = 0; i < blocks; i++) {
          Serial.println(num[i]);
        }
        /*String sum = num[0][0] + num[1][0];
        String sum1 = num[0][1] + num[1][1];
        String sum2 = sum + op[0];
        int sumx = sum.toInt();
        int sumy = sum1.toInt();
        int sumz = sum2.toInt();
        Serial.println(sum);
        Serial.println(sum1);
        Serial.println(op[0]);
        Serial.println(sum2);
        Serial.println(sumz + sumy);*/
      }
    }
  }

  if (position != 0) {
    if (digitalRead(ButtonPlus) == LOW) {
      delay(50);
      if (digitalRead(ButtonPlus) == HIGH) {
        delay(50);
        logical_operator("+");
      }
    }
  }

  if (position != 0) {
    if (digitalRead(ButtonMinus) == LOW) {
      delay(50);
      if (digitalRead(ButtonMinus) == HIGH) {
        delay(50);
        logical_operator("-");
      }
    }
  }


  // Limpar a tela
  if (digitalRead(ButtonClear) == LOW) {
    delay(50);
    if (digitalRead(ButtonClear) == HIGH) {
      delay(50);
      String num[15];
      blocks, position = 0;
      lcd.clear();
    }
  }
}
