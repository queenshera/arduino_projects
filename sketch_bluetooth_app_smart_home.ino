#include <SoftwareSerial.h>

#define sw1 2
#define sw2 3
#define sw3 4
#define sw4 5

SoftwareSerial BTSerial(10, 11); // RX | TX

char c;

void setup() 
{
  pinMode(sw1, OUTPUT);
  pinMode(sw2, OUTPUT);
  pinMode(sw3, OUTPUT);
  pinMode(sw4, OUTPUT);
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  
  Serial.begin(9600);
  BTSerial.begin(9600);
  delay(1000);
}

void loop() 
{
  while (BTSerial.available()){
    
    delay(10);
    c = BTSerial.read();

    Serial.print(c);

    switch(c)
    {
      case '1':{
        digitalWrite(sw1, LOW);
        break;
      }
      case '2':{
        digitalWrite(sw1, HIGH);
        break;
      }
      case '3':{
        digitalWrite(sw2, LOW);
        break;
      }
      case '4':{
        digitalWrite(sw2, HIGH);
        break;
      }
      case '5':{
        digitalWrite(sw3, LOW);
        break;
      }
      case '6':{
        digitalWrite(sw3, HIGH);
        break;
      }
      case '7':{
        digitalWrite(sw4, LOW);
        break;
      }
      case '8':{
        digitalWrite(sw4, HIGH);
        break;
      }
      case '9':{
        digitalWrite(sw1, LOW);
        digitalWrite(sw2, LOW);
        digitalWrite(sw3, LOW);
        digitalWrite(sw4, LOW);
        break;
      }
      case '0':{
        digitalWrite(sw1, HIGH);
        digitalWrite(sw2, HIGH);
        digitalWrite(sw3, HIGH);
        digitalWrite(sw4, HIGH);
        break;
      }
      default:{
        digitalWrite(sw1, HIGH);
        digitalWrite(sw2, HIGH);
        digitalWrite(sw3, HIGH);
        digitalWrite(sw4, HIGH);
      }
    }
  }
}
