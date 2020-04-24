#include <NewPing.h>

#define LEFTINDICATOR 2
#define RIGHTINDICATOR 3
#define INDICATORSDELAY 300 
#define BRAKELIGHT 4

#define MOTORLEFTUP 5
#define MOTORLEFTDOWN 6
#define MOTORLEFTSPEED 9

#define MOTORRIGHTUP 8
#define MOTORRIGHTDOWN 7
#define MOTORRIGHTSPEED 10

char indicators = 'n';
NewPing sonar(12, 11);

void setup() {
  pinMode(LEFTINDICATOR, OUTPUT);
  pinMode(RIGHTINDICATOR, OUTPUT);
  pinMode(BRAKELIGHT, OUTPUT);
  pinMode(MOTORLEFTUP, OUTPUT);
  pinMode(MOTORLEFTDOWN, OUTPUT);
  pinMode(MOTORRIGHTUP, OUTPUT);
  pinMode(MOTORRIGHTDOWN, OUTPUT);
  Serial.begin(9600);
  Serial.write("AT\r\n");
  // you can change 5454 to your password
  Serial.write("AT+PSWD=4545\r\n");
  // you can change arduino_robot to your name
  Serial.write("AT+NAME=arduino_robot\r\n");
}

void loop() { 
  Serial.write('d');
  Serial.write(sonar.ping_cm());
  if(Serial.available()){
    char data = Serial.read();
    switch(data)
    {
      case 'i':
        Serial.write('i');
        Serial.write(indicators);
      case 'l':
        indicators = 'l';
        break;
      case 'r':
        indicators = 'r';
        break;
      case 'e':
        indicators = 'e';
        break;
      case 'n':
        indicators = 'n';
        break;
      case 'B':
        digitalWrite(BRAKELIGHT, HIGH);
        break;
      case 'b':
        digitalWrite(BRAKELIGHT, LOW);
        break;
      case 'L':
        if(Serial.available())
        {
          data = Serial.read();
          analogWrite(MOTORLEFTSPEED, data);
        }
        break;
      case 'R':
        if(Serial.available())
        {
          data = Serial.read();
          analogWrite(MOTORRIGHTSPEED, data);
        }
        break;
      case 'Z':
        digitalWrite(MOTORLEFTDOWN, LOW);
        digitalWrite(MOTORLEFTUP, HIGH);
        break;
      case 'z':
        digitalWrite(MOTORLEFTUP, LOW);
        digitalWrite(MOTORLEFTDOWN, HIGH);
        break;
      case 'X':
        digitalWrite(MOTORRIGHTDOWN, LOW);
        digitalWrite(MOTORRIGHTUP, HIGH);
        break;
      case 'x':
        digitalWrite(MOTORRIGHTUP, LOW);
        digitalWrite(MOTORRIGHTDOWN, HIGH);
        break;
    }
  }
  delay(INDICATORSDELAY);
  switch(indicators){
    case 'l':
      digitalWrite(LEFTINDICATOR, HIGH);
      delay(INDICATORSDELAY);
      digitalWrite(LEFTINDICATOR, LOW);
      break;
    case 'r':
      digitalWrite(RIGHTINDICATOR, HIGH);
      delay(INDICATORSDELAY);
      digitalWrite(RIGHTINDICATOR, LOW);
      break;
    case 'e':
      digitalWrite(LEFTINDICATOR, HIGH);
      digitalWrite(RIGHTINDICATOR, HIGH);
      delay(INDICATORSDELAY);
      digitalWrite(LEFTINDICATOR, LOW);
      digitalWrite(RIGHTINDICATOR, LOW);
      break;
  }
}
