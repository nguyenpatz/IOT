//#include <Arduino.h>
//#include <ESP8266WiFi.h>
//#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
//#include <Wire.h>
//using namespace std;
//WebSocketsClient webSocket;
//const char* ssid = "Wifi5g"; //Đổi thành wifi của bạn
//const char* password = "playbasketball"; //Đổi pass luôn
//const char* ip_host = "192.168.1.251"; //Đổi luôn IP host của PC nha
//const uint16_t port = 3000; //Port thích đổi thì phải đổi ở server nữa
//const int LED = 2;
//const int BTN = 0;
//byte wireArray[1];
//char myBuffer [33];
//int val1;
//int val2;
//String val;
//
//
//void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
//  switch (type) {
//    case WStype_DISCONNECTED:
//      Serial.printf("[WSc] Disconnected!\n");
//      break;
//    case WStype_CONNECTED:
//      {
//        Serial.printf("[WSc] Connected to url: %s\n", payload);
//      }
//      break;
//    case WStype_TEXT:
//      Serial.printf("[WSc] get text: %s\n", payload);
//      if (strcmp((char*)payload, "ON") == 0) {
//        digitalWrite(LED, 0); // Khi client phát sự kiện "LED_ON" thì server sẽ bật LED
//      } else if (strcmp((char*)payload, "OFF") == 0) {
//        digitalWrite(LED, 1); // Khi client phát sự kiện "LED_OFF" thì server sẽ tắt LED
//      }
//      break;
//    case WStype_BIN:
//      Serial.printf("[WSc] get binary length: %u\n", length);
//      break;
//  }
//}
//
//void getRequestFromArduino() {
////  byte index = 0;
////  Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
////  while (Wire.available() && index < 4) {
////    wireArray[index] = Wire.read();
////    index++;
//////    int a = Wire.read();
////    //    myData = String(c);
//////    myData = itoa(a, c, 10);
//////    Serial.print(myData.to_String());
////  }
////  val1 = wireArray[0];
////  Serial.print("data 1: ");
////  Serial.println(val1);
////  //  delay(1000);
//
//int index = 0;
//  Wire.requestFrom(8, 6);
//  while (Wire.available() > 0 && index <1)
//  {
//    wireArray[index] = Wire.read();
//    index++;
//  }
//  val1 = wireArray[0]; 
////  val2 = wireArray[2]; 
//  Serial.println("data thu 1");
//  Serial.println(val1);
////  Serial.println("data thu 2");
////  Serial.println(val2);
//}
//
//
//void setup() {
//  pinMode(LED, OUTPUT);
//  pinMode(BTN, INPUT);
//  Serial.begin(115200);
//  Wire.begin(D1, D2);
//  Serial.println("ESP8266 Websocket Client");
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  webSocket.begin(ip_host, port);
//  webSocket.onEvent(webSocketEvent);
//
//}
//void loop() {
//  getRequestFromArduino();
//  val = itoa(val1,myBuffer,10);
//  webSocket.loop();
//  webSocket.sendTXT(val); //"%s", myData
//  //  sendMyData();
//  //  static bool isPressed = false;
//  //  if (!isPressed && digitalRead(BTN) == 0) { //Nhấn nút nhấn GPIO0
//  //    isPressed = true;
//  //    webSocket.sendTXT("BTN_PRESSED");
//  //  } else if (isPressed && digitalRead(BTN)) { //Nhả nút nhấn GPIO0
//  //    isPressed = false;
//  //    webSocket.sendTXT("BTN_RELEASE");
//  //  }
//}
//
//void sendMyData() {
//  Wire.beginTransmission(8);
//  Wire.write("Hello Arduino");
//  Wire.endTransmission();
//}
//

























//#include <Arduino.h>
//#include <ESP8266WiFi.h>
//#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
//#include <Wire.h>
//
//WebSocketsClient webSocket;
//const char* ssid = "Wifi5g"; //Đổi thành wifi của bạn
//const char* password = "playbasketball"; //Đổi pass luôn
//const char* ip_host = "192.168.1.251"; //Đổi luôn IP host của PC nha
//const uint16_t port = 8000; //Port thích đổi thì phải đổi ở server nữa
//const int LED = 2;
//const int BTN = 0;
//byte wireArray[4];
//char myBuffer [33];
//int val1;
//int val2;
//String val;
//
//void getData(){
//  byte index = 0;
//  Wire.requestFrom(8, 6);
//  while (Wire.available() > 0 && index <4)
//  {
//    wireArray[index] = Wire.read();
//    index++;
//  }
//  val1 = wireArray[0]; 
//  val2 = wireArray[2]; 
//}
//
//void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
//  switch (type) {
//    case WStype_DISCONNECTED:
//      Serial.printf("[WSc] Disconnected!\n");
//      break;
//    case WStype_CONNECTED:
//      {
//        Serial.printf("[WSc] Connected to url: %s\n", payload);
//      }
//      break;
//    case WStype_TEXT:
//      Serial.printf("[WSc] get text: %s\n", payload);
//      if (strcmp((char*)payload, "ON") == 0) {
//        Wire.beginTransmission(8); /* begin with device address 8 */
//        Wire.write(1);  /* sends hello string */
//        Wire.endTransmission();    /* stop transmitting */
//        // Khi client phát sự kiện "ON" thì server sẽ bật LED
//      } else if (strcmp((char*)payload, "OFF") == 0) {
//        Wire.beginTransmission(8); /* begin with device address 8 */
//        Wire.write(0);  /* sends hello string */
//        Wire.endTransmission();    /* stop transmitting */
//        // Khi client phát sự kiện "ON" thì server sẽ bật LED
//      }
//      break;
//    case WStype_BIN:
//      Serial.printf("[WSc] get binary length: %u\n", length);
//      if (length == 6) {
//
//      } else if (length == 7) {
//
//      }
//      break;
//  }
//}
//void setup() {
//  pinMode(LED, OUTPUT);
//  pinMode(BTN, INPUT);
//  Serial.begin(115200);
//  Wire.begin(D1, D2);
//  Serial.println("ESP8266 Websocket Client");
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  webSocket.begin(ip_host, port);
//  webSocket.onEvent(webSocketEvent);
//}
//void loop() {
//  webSocket.loop();
//  getData();
//  
////  chuyển dữ liệu thành chuỗi
//  val = itoa(val1,myBuffer,10);
//  val +=" ";
//  val += itoa(val2,myBuffer,10);
//  Serial.println(val);
////  Gửi dữ liệu
//  webSocket.sendTXT(val);
//}


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
#include <Wire.h>

WebSocketsClient webSocket;
const char* ssid = "Wifi5g"; //Đổi thành wifi của bạn
const char* password = "playbasketball"; //Đổi pass luôn
const char* ip_host = "192.168.1.251"; //Đổi luôn IP host của PC nha
const uint16_t port = 8000; //Port thích đổi thì phải đổi ở server nữa
const int LED = 2;
//const int BTN = 0;
byte wireArray[4];
char myBuffer [33];
int val1;
int val2;
String val;


//Hàm lấy dữ liệu
void getData(){
  byte index = 0;
  Wire.requestFrom(8, 6);
  while (Wire.available() > 0 && index <4)
  {
    wireArray[index] = Wire.read();
    index++;
  }
  val1 = wireArray[0]; 
  val2 = wireArray[2]; 
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED:
      {
        Serial.printf("[WSc] Connected to url: %s\n", payload);
      }
      break;
    case WStype_TEXT:
//      Serial.printf("[WSc] get text: %s\n", payload);
      if (strcmp((char*)payload, "ON") == 0) {
        Serial.println((char*)payload);
        Wire.beginTransmission(8); /* bắt đầu bằng địa chỉ thiết bị 8 */
        Wire.write(1);  /* gửi giá trị 1 */
        Wire.endTransmission();    /* ngừng truyền */
        // Khi client phát sự kiện "ON" thì server sẽ bật LED
      } else if (strcmp((char*)payload, "OFF") == 0) {
        Serial.println((char*)payload);
        Wire.beginTransmission(8); /* bắt đầu bằng địa chỉ thiết bị 8 */
        Wire.write(0);  /* gửi giá trị 0 */
        Wire.endTransmission();    /* stop transmitting */
        // Khi client phát sự kiện "ON" thì server sẽ bật LED
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      if (length == 6) {

      } else if (length == 7) {

      }
      break;
  }
}
void setup() {
  pinMode(LED, OUTPUT);
  //pinMode(BTN, INPUT);
  Serial.begin(115200);
  Wire.begin(D1, D2);
  Serial.println("ESP8266 Websocket Client");
  WiFi.begin(ssid, password); // kết nối wifi 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  webSocket.begin(ip_host, port); //kích hoạt địa chỉ ip và port để có thể truy cập vào
  webSocket.onEvent(webSocketEvent); // Nhận sự kiện 
}
void loop() {
  webSocket.loop();
  getData();
  
//  chuyển dữ liệu thành chuỗi
  val = itoa(val1,myBuffer,10);
  val +=" ";
  val += itoa(val2,myBuffer,10);
//  Serial.println(val);
//  Gửi dữ liệu
  webSocket.sendTXT(val);
}
