#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

#define enA 3
#define enB 9
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define horn 12

char c;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(horn, OUTPUT);
  
  Serial.begin(9600);
  BTSerial.begin(9600);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTSerial.available()){
    
    delay(10);
    c = BTSerial.read();

    Serial.print(c);

    driveMotors();
    if(c=='H'){
      Serial.println("Horn");
      digitalWrite(horn,HIGH);
    }
    if(c=='N'){
      Serial.println("No Horn");
      digitalWrite(horn,LOW);
    }
  }
}

void driveMotors(){

  if(c=='S'){
    Serial.println("S");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }
  if(c=='R'){
    Serial.println("R");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (enA, 0);
    analogWrite (enB, 70);
  }
  if(c=='L'){
    Serial.println("L");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite (enA, 70);
    analogWrite (enB, 0);
    
  }
  if(c=='B'){
    Serial.println("B");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite (enA, 70);
    analogWrite (enB, 70);
  }
  if(c=='F'){
    Serial.println("F");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (enA, 70);
    analogWrite (enB, 70);
  }
}
