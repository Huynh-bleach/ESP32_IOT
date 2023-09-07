
#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#include <ESP32Servo.h>

#include "index.h"


//---------------------------------------- tao bien co ham delay vaf gia tri dieu kieen de dieu khien cac thiet bi trong nha kinh//





//-------------------------------------------------------------------------------------

#define ServoPort 13
#define ServoPortboss 14 

#define LED 33
#define FAN 25
#define PUMP 26 

Servo myservo;
Servo myservoboss;

#define chandht 27
#define loaidht DHT11



DHT dht(chandht,loaidht);

float nhietdo;
float doam;
float nhietdoF;

const char* tenwifi = "OPPO A31";
const char* mkwifi = "99999999";
WebServer server(80);

void ketnoi(){
  String s = MAIN_page; 
  server.send(200,"text/html",s);
}

void docdulieunhietdo(){
  nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo)){
    server.send(200,"text/plane","Failed");
  }else{
    server.send(200,"text/plane",snhietdo);
  }
}


void docdulieunhietdoF(){
  nhietdoF = dht.readTemperature(true);
  String snhietdoF = String(nhietdoF);
  if(isnan(nhietdoF)){
    server.send(200, "text/plane","Failed");
  }
  else{
    server.send(200, "text/plane",snhietdoF);
  }
  
  
}


void docdulieudoam(){
  doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam)){
    server.send(200,"text/plane","Failed");
  }else{
    server.send(200,"text/plane",sdoam);
  }
}
//------------------------------------------------------
void docdulieudoamdat(){
  int analog = 0;
  for(int i=0;i<=9;i++){
  analog += analogRead(14);
              }
  float analogValue = analog/10;

  long int percent;

  percent  = map(analogValue, 350, 4096, 0, 100);    // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100. 
                                                  // Cái này sẽ bằng thực nghiệm nhé
  percent=100-percent;

  String spercent = String(percent);
  if(percent > 101){
    server.send(200,"text/plane","Failed");
  }else{
    server.send(200,"text/plane",spercent);
  }
            
  
}

void docdulieuanhsang(){
  int giatri;
  giatri = digitalRead(13);
  String anhsang;
  if( giatri == 1){
        anhsang = "Dang toi";
                 
       }
    else{
    anhsang = "Dang sang";
    }
  
  if(isnan(giatri)){
    server.send(200,"text/plane","Failed");
  }else{
    server.send(200,"text/plane",anhsang);
  }

  
  
  
}
//----------------------------------------------------


// ------------------ham dieu khien cac thiet bi



void handleLEDon() { 
 String s = MAIN_page;
 Serial.println("LED on page");
 digitalWrite(LED,HIGH); //LED is connected in reverse
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}

void handleLEDoff() { 
 String s = MAIN_page; 
 Serial.println("LED off page");
 digitalWrite(LED,LOW); //LED off
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}



//-----------------FAN
void handleFANon() { 
 String s = MAIN_page;
 Serial.println("FAN on page");
 digitalWrite(FAN,HIGH); //LED is connected in reverse
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}

void handleFANoff() { 
 String s = MAIN_page; 
 Serial.println("FAN off page");
 digitalWrite(FAN,LOW); //LED off
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}


//--------------------------PUMP

void handlePUMPon() { 
 String s = MAIN_page;
 Serial.println("PUMP on page");
 digitalWrite(PUMP,HIGH); //LED is connected in reverse
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}

void handlePUMPoff() { 
 String s = MAIN_page; 
 Serial.println("PUMP off page");
 digitalWrite(PUMP,LOW); //LED off
 server.send(200, "text/html", s); //Send ADC value only to client ajax request
}


//-----------------------------------------------------------


// -------------------- dieu khien servo
//------------------ servo --1
void handleServo(){
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();

  myservo.write(pos);   
  delay(60);
  Serial.print("Servo Angle:");
  Serial.println(pos);
  
  server.send(200, "text/plane","");
}


// ------------------ servo --2

void handleServoboss(){
  String BOSS = server.arg("servoBOSS");
  int boss = BOSS.toInt();
  myservoboss.write(boss);   //--> Move the servo motor according to the POS value
  delay(60);
  Serial.print("Servo Angle boss:");
  Serial.println(boss);
  server.send(200, "text/plane","");
}

//----------------------------------------




void setup() {
  Serial.begin(115200);
  pinMode(chandht,INPUT);
  dht.begin();


// ---------------- setup

  pinMode(LED,OUTPUT); 
  //Power on LED state off
  digitalWrite(LED,HIGH);


  pinMode(FAN,OUTPUT); 
  //Power on LED state off
  digitalWrite(FAN,HIGH);

    pinMode(PUMP,OUTPUT); 
  //Power on LED state off
   digitalWrite(PUMP,HIGH);
 

//----------
  
  Serial.println("");
  Serial.print("Ket noi den wifi ");
  Serial.println(tenwifi);
  WiFi.begin(tenwifi, mkwifi);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi da duoc ket noi");
  Serial.println("dia chi IP: ");
  Serial.println(WiFi.localIP());
  
  server.on("/",ketnoi);


 myservo.attach(ServoPort);
 myservoboss.attach(ServoPortboss);

 
  
//myservo.write(0);
//delay(2000);
//myservo.write(180);
  
  server.on("/docnhietdo",docdulieunhietdo);
  server.on("/docnhietdoF",docdulieunhietdoF);
  
  server.on("/docdoam",docdulieudoam);
  //-------------------------------
  server.on("/docdoamdat",docdulieudoamdat);
  server.on("/docanhsang",docdulieuanhsang);


  // goi ham dieu khien button

  server.on("/ledOn", handleLEDon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff", handleLEDoff);


  //------------------------------FAN
  server.on("/fanOn", handleFANon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/fanOff", handleFANoff);
  //--------------------------------PUMP
    server.on("/pumpOn", handlePUMPon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/pumpOff", handlePUMPoff);


  //----------------------


  server.on("/setPOS",handleServo);
  server.on("/setBOSS",handleServoboss);
  
  
  server.begin();
}

void loop() {
  server.handleClient();
}
