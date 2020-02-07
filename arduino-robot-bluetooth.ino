#define LEFTINDICATOR 2
#define RIGHTINDICATOR 3
#define INDICATORSDELAY 300 

char indicators = 'n';

void setup() {
  pinMode(LEFTINDICATOR, OUTPUT);
  pinMode(RIGHTINDICATOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char data = Serial.read();
    switch(data)
    {
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
