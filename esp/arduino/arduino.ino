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

const int ledPin = 13; // Chỗ cắm chân đèn led

const int ldrPin = A0; // chỗ cắm chân cảm biến ánh sáng

const int pirPin = 2; // chỗ cắm chân cảm biến chuyển động

int ldrStatus = 0; // biến để lưu giá trị cảm biến ánh sáng

int pirStatus = 0; // biến để lưu giá trị cảm biến chuyển động

int myData[2]; // lưu giá trị cảm biến rồi đẩy lên esp

void combine2Sensor() { // hàm này để lấy dữ liệu của 2 cảm biến

  ldrStatus = analogRead(ldrPin);

  pirStatus = digitalRead(pirPin);

  myData[0] = ldrStatus; // lưu cảm biến ánh sáng vào mảng có vị trí là 0
 
  myData[1] = pirStatus; // cảm biến chuyển động vào mảng có vị trí là 1

  Serial.println((byte)myData[0]);

  Serial.println((byte)myData[1]);
}


void setup() {

 pinMode(ledPin, OUTPUT);

 pinMode(ldrPin, INPUT);

 pinMode(pirPin, INPUT);

 Wire.begin(8);                /* Kết nối i2c với địa chỉ 8 */

 Wire.onReceive(receiveEvent); /* Nhận dữ liệu từ esp*/

 Wire.onRequest(requestEvent); /* Gửi dữ liệu lên esp */

 Serial.begin(115200);           /* Bắt đầu với serial có tốc độ ký tự là 115200 */
 
}

void loop() {

  combine2Sensor();
}

// Nhận sự kiện
void receiveEvent(int howMany) { // Hàm này để bật tắt đèn khi có lệnh từ trình duyệt gửi về esp sau đó esp gửi về arduino lệnh bật tắt
 while (0 <Wire.available()) {

    int c = Wire.read();      /* receive byte as a character */

    if(c == 1) {

      digitalWrite(ledPin, c); // 1 - HIGH là bật đèn

    } else {

      digitalWrite(ledPin, c); // else -> c = 0 = LOW là tắt đèn
    }

  }

 Serial.println();             /* In xuống dòng */
}

// Gửi yêu cầu hoặc data
void requestEvent() {

 Wire.write((byte *) myData, sizeof myData);  /*Gửi giá trị cảm biến từ arduino -> esp */
 
}
