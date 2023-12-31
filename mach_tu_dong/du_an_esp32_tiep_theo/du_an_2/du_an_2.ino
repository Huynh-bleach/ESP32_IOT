
#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFiManager.h>


#include "index_2.h"


LiquidCrystal_I2C lcd(0x27, 20, 4);



//---------------------------------------- tao bien co ham delay vaf gia tri dieu kieen de dieu khien cac thiet bi trong nha kinh//





//-------------------------------------------------------------------------------------
// khai bao bien chan dieu khien 2 servo ---------------------------------
#define ServoPort 13
#define ServoPortboss 14 


// khai bao 3 chaan dieu khien dong co ------------------------------
#define LED    18
#define FAN    17
#define PUMP   16

// Dinh nghia ham servo -----------------------------
Servo myservo;
Servo myservoboss;


// khai bao chan nhan du lieu tu cac cam bien ---------------------------------
//#define chancb_dat 25
//#define chancb_anhsang 27
#define chandht 23
#define loaidht DHT11


// khai bao bien nhan gia tri tu cam bien --------------------------------------
DHT dht(chandht,loaidht);
float nhietdo;
float doam;
float nhietdoF;



// -------------- khai bao bien kiem tra nhiet do 
int kiemtraNT;
int kiemtraDAD;


// ------------------ khai bao bien thoi luong hoat dong cua thiet bi
int timeNT;
int timeDAD;

//---------------------------------------

//-------------khai bao biên nhan gia tri hien thi tren LCD

String LCDNT;
String LCDNTF;
String LCDDA;
String LCDDAD;
String LCDAS;
///-----------------------

// -------------------------- khai bao ten wifi vaf mat khau
const char* tenwifi = "OPPO A15s";
const char* mkwifi = "11111111";



WebServer server(80);

void ketnoi(){
  String s = MAIN_page; 
  server.send(200,"text/html",s);
}
// ------------------------------------------------------------------ ham doc gia tri nhiet do
void docdulieunhietdo(){
  nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo)){
    LCDNT = "nan";
    server.send(200,"text/plane","Failed");
  }else{
    LCDNT = snhietdo;
    server.send(200,"text/plane",snhietdo);
    
    
  }
}

//----------------------------------------------------------------------------------- ham doc gia tri nhiet do theo F
void docdulieunhietdoF(){
  nhietdoF = dht.readTemperature(true);
  String snhietdoF = String(nhietdoF);
  if(isnan(nhietdoF)){
    LCDNTF = "nan";
    server.send(200, "text/plane","Failed");
  }
  else{
    LCDNTF = snhietdoF;
    server.send(200, "text/plane",snhietdoF);
  }
  
  
}

// ------------------------------------------------------------------------------------- ham doc gia tri do am
void docdulieudoam(){
  doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam)){
    LCDDA = "nan";
    server.send(200,"text/plane","Failed");
  }else{
    LCDDA = sdoam;
    server.send(200,"text/plane",sdoam);
  }
}
//---------------------------------------------------------------------------------- ham doc gia tri do am dat 
void docdulieudoamdat(){
  int analog;
  analog = analogRead(35);
              
  int percent;

  percent  = map(analog, 4095, 2100, 0, 100);    // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100. 
                                                  // Cái này sẽ bằng thực nghiệm nhé
  //Serial.print("Gia tri do am dat: ");
  //Serial.print(percent);
  //Serial.print("---   ");
  //Serial.println(analog);

  String spercent = String(percent);
  if(percent > 110){
    LCDDAD = "nan";
    server.send(200,"text/plane","Failed");
  }else{
    LCDDAD = spercent;
    server.send(200,"text/plane",spercent);
  }
             
}

// ----------------------------------------------------------------------------------------- ham doc gia tri anh sang
void docdulieuanhsang(){
  int giatri;
  giatri = analogRead(39);

  int percentas = map(giatri, 600, 4095, 0, 100);
  String anhsang;
  if(percentas > 50){
        anhsang = "Dang toi";
                 
       }
    else{
    anhsang = "Dang sang";
    }
  
  if(percentas < -5){
    LCDAS = "nan";
    server.send(200,"text/plane","Failed");
  }else{
    LCDAS = anhsang;
    server.send(200,"text/plane",anhsang);
  }

  
  
  
}
//----------------------------------------------------


// ------------------ ---------------------------------------------------ham dieu khien cac thiet bi


// -------------------------------------------------dieu khien LED
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



//-------------------------------------------------------------FAN
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


//-----------------------------------------------------------------PUMP

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


// ----------------------------------------------------------------------- ham dieu khien servo
//------------------  -----------------------------------servo --1
void handleServo(){
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();

  myservo.write(pos);   
  delay(60);
  Serial.print("Servo Angle:");
  Serial.println(pos);
  
  server.send(200, "text/plane","");
}


// ------------------ ---------------------------------servo --2

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

//-------------------------- -----------------------------HAm lay gia tri kiem tra va thoi gian hoat dong cua thiet bi
//-----------------------------
void handlekiemtraNT(){
  String KTNT = server.arg("KTNT");
  kiemtraNT = KTNT.toInt();
  
  delay(60);
  Serial.print("Dieu kien kiem tra nhiet do: ");
  Serial.println(kiemtraNT);
  
  server.send(200, "text/plane","");
}



void handlekiemtraDAD(){
  String KTDAD = server.arg("KTDAD");
  kiemtraDAD = KTDAD.toInt();
  
  delay(60);
  Serial.print("Dieu kien kiem tra do am dat: ");
  Serial.println(kiemtraDAD);
  
  server.send(200, "text/plane","");
}







//-----------------------------


//----------------------------------------------------------------- ham setup lcd
void handleLCDsetup(){
  lcd.init();
  lcd.clear();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  
  lcd.print("GIAM SAT NONG NGHIEP");
  
  lcd.setCursor(0,1);
  lcd.print("ND:");
  lcd.setCursor(7,1);
  lcd.print("C");
  
  lcd.setCursor(10,1);
  lcd.print("NDF:");
  lcd.setCursor(18,1);
  lcd.print("F");
  
  lcd.setCursor(0,2);
  lcd.print("DA:");
  lcd.setCursor(7,2);
  lcd.print("%");
  
  lcd.setCursor(10,2);
  lcd.print("DAD:");
  lcd.setCursor(18,2);
  lcd.print("%");
  
  lcd.setCursor(4,3);
  lcd.print("THAS:");

}

// --------------------------------------- ham hien thi gia tri tu cam bien hien thi len LCD
void handleLCDGS(){
  lcd.setCursor(3,1);
  lcd.print(LCDNT);
  

  lcd.setCursor(14,1);
  lcd.print(LCDNTF);

  
  lcd.setCursor(3,2);
  lcd.print(LCDDA);

  lcd.setCursor(14,2);
  lcd.print(LCDDAD);


  lcd.setCursor(9,3);
  lcd.print(LCDAS);
}







void setup() {
  Serial.begin(115200);
  pinMode(chandht,INPUT);
  

  pinMode(35,INPUT);
  
  pinMode(39,INPUT);

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
   
   handleLCDsetup();
 

//----------
 WiFi.mode(WIFI_STA);
 WiFiManager wm;

 bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
        Serial.println(WiFi.localIP());
    }
  
  
  server.on("/",ketnoi);

  myservo.attach(ServoPort);
  myservoboss.attach(ServoPortboss);


  
  
  server.on("/docnhietdo",docdulieunhietdo);
  server.on("/docnhietdoF",docdulieunhietdoF); 
  server.on("/docdoam",docdulieudoam);
  
  //-------------------------------
  
  server.on("/docdoamdat",docdulieudoamdat);
  server.on("/docanhsang",docdulieuanhsang);

//---------- goi ham dieu khien button
  
  // -------------------------------LED
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


  server.on("/setKTNT",handlekiemtraNT);
  server.on("/setKTDAD",handlekiemtraDAD);

  
  server.begin();
}

void loop() {
  server.handleClient();
  handleLCDGS();
}
