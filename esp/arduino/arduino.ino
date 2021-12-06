//#include <Wire.h>
//const int ledPin = 13;
//const int ldrPin = A0;
//const int pirPin = 2;
//int ldrStatus = 0;
//int pirStatus = 0;
//int myData[2];
//
////https://arduinogetstarted.com/tutorials/arduino-relay
////nguồn để cắm led relay 
//
//void combine2Sensor() {
//  ldrStatus = analogRead(ldrPin);
//  pirStatus = digitalRead(pirPin);
//  myData[0] = ldrStatus;
//  myData[1] = pirStatus;
//  Serial.println((byte)myData[0]);
//  Serial.println((byte)myData[1]);
//}
//
//
//void setup() {
// pinMode(ledPin, OUTPUT);
// pinMode(ldrPin, INPUT);
// pinMode(pirPin, INPUT);
// Wire.begin(8);                /* join i2c bus with address 8 */
// Wire.onReceive(receiveEvent); /* register receive event */
// Wire.onRequest(requestEvent); /* register request event */
// Serial.begin(115200);           /* start serial for debug */
// 
//}
//
//void loop() {
//  combine2Sensor();
//}
//
//// Nhận sự kiện
//void receiveEvent(int howMany) {
// while (0 <Wire.available()) {
//    int c = Wire.read();      /* receive byte as a character */
//    if(c == 1) {
//      digitalWrite(ledPin, c);
//    } else {
//      digitalWrite(ledPin, c);
//    }
//  }
// Serial.println();             /* to newline */
//}
//
//// Gửi yêu cầu hoặc data
//void requestEvent() {
// Wire.write((byte *) myData, sizeof myData);  /*send string on request */
//}

#include <Wire.h>
const int ledPin = 13;
const int ldrPin = A0;
const int pirPin = 2;
int ldrStatus = 0;
int pirStatus = 0;
int myData[2];

void combine2Sensor() {
  ldrStatus = analogRead(ldrPin);
  pirStatus = digitalRead(pirPin);
  myData[0] = ldrStatus;
  myData[1] = pirStatus;
  Serial.println((byte)myData[0]);
  Serial.println((byte)myData[1]);
}


void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(ldrPin, INPUT);
 pinMode(pirPin, INPUT);
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(115200);           /* start serial for debug */
 
}

void loop() {
  combine2Sensor();
}

// Nhận sự kiện
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    int c = Wire.read();      /* receive byte as a character */
    if(c == 1) {
      digitalWrite(ledPin, c);
    } else {
      digitalWrite(ledPin, c);
    }
  }
 Serial.println();             /* to newline */
}

// Gửi yêu cầu hoặc data
void requestEvent() {
 Wire.write((byte *) myData, sizeof myData);  /*send string on request */
}
