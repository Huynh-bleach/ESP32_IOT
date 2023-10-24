// This example uses an ESP32 Development Board
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://www.shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <WiFi.h>
#include <MQTT.h>
#include <Arduino_JSON.h>
const int ledPin = 2;
const char ssid[] = "HA-PHUONG";
const char pass[] = "haphuong123456789";

String image = "https://static.lag.vn/upload/news/23/07/14/jujutsu-kaisen-giai-thich-suc-manh-thuat-thuc-gojo-satoru_AUQY.jpg";

WiFiClient net;
MQTTClient client;

String jsonString;
unsigned long lastMillis = 0;

  JSONVar data;
 

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "huynh", "1611")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("arduino");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {

  Serial.println("incoming: " + topic + " - " + payload);
  /*
  JSONVar myObject = JSON.parse(payload);
  //Serial.println((int) myObject["val"]);
  if((int) myObject["kind"]==3 &&(int) myObject["val"]==0){
    Serial.println("tat");
    digitalWrite (ledPin, LOW);  // turn off the LED
  }
  else{
    Serial.println("mo");
    digitalWrite (ledPin, HIGH);  // turn on the LED
  }*/
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  pinMode(ledPin, OUTPUT);
  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin("192.168.1.110", 1883, net);
  client.onMessage(messageReceived);

  connect();
  
  data["temp"] = 20;
  data["tempforF"] = 40;
  data["humi"] = 50;
  data["solid"] = 60;
  data["light"] = 70;

  
  data["PWMled"] = 10;
  data["PWMfan"] = 20;
  data["PWMpump"] = 39;
  

  
  
  jsonString = JSON.stringify(data);

  xTaskCreatePinnedToCore(sendOject,"senddata", 2028, NULL, 5, null, 1);


}
  
  
void loop() {
  
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability
  

  if (!client.connected()) {
    connect();
  }

  
}


void sendOject(void *pvParameters){
  (void)pvParameters;
  Serial.println(jsonString);
  
  client.publish("C3", jsonString);

  vTaskDelay(pdMS_TO_TICKS(4000));

}


