#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "1234"; // change your password here
String input_password;
int lockOutput = 11;
void setup(){
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
  pinMode(lockOutput, OUTPUT);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    Serial.println(key);

    if(key == '*') {
      input_password = ""; // clear input password
    } else if(key == '#') {
      if(password == input_password) {
        Serial.println("dobrodesel doma :-) ");
        // DO YOUR WORK HERE
        digitalWrite(lockOutput, HIGH);
        delay(5000);
        digitalWrite(lockOutput, LOW);
        
      } else {
        Serial.println("vstop zavrnjen");
      }

      input_password = ""; // clear input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}
