#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <WebServer.h>
#include "web.h"

#define EEPROM_SIZE 100

#define EEPROM_ADDR 10

#define chancb_dat 35
#define chancb_anhsang 39
#define chandht 23
#define loaidht DHT11

#define ledPin 18
#define fanPin 17
#define pumpPin 16

#define buttonled 15
#define buttonfan 2
#define buttonpump 4


DHT dht(chandht, loaidht);
float nhietdo;
float doam;
float nhietdoF;

float doamdat;
float anhsang;

String LCDNT;
String LCDNTF;
String LCDDA;
String LCDDAD;
String LCDAS;


int pwmChannel1 = 0;    // PWM channel for pin 16
int pwmChannel2 = 1;    // PWM channel for pin 17
int pwmChannel3 = 2;    // PWM channel for pin 18
int pwmFreq = 5000;     // Frequency in Hz
int pwmResolution = 8;  // Resolution in bits (1-16)



int save = 0;
int loca = 18;
int speedFAN = 30;
int brightnessLED = 50;
int speedPUMP = 10;
String tam;
int KT;
int selection = 0;

unsigned char onOffled = 0;
unsigned char onOfffan = 0;
unsigned char onOffpump = 0;

String image;
int Controls = 1;

#define ROW_NUM 4     // four rows
#define COLUMN_NUM 4  // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pin_rows[ROW_NUM] = { 32, 33, 25, 26 };       // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte pin_column[COLUMN_NUM] = { 27, 14, 12, 13 };  // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);
LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address 0x27, 16 column and 2 rows

int cursorColumn = 0;


WebServer server(80);
void setup() {
  Serial.begin(9600);
  pinMode(chandht, INPUT);

  pinMode(chancb_anhsang, INPUT);

  pinMode(chancb_dat, INPUT);
  dht.begin();


  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  pinMode(buttonled, INPUT_PULLUP);
  pinMode(buttonfan, INPUT_PULLUP);
  pinMode(buttonpump, INPUT_PULLUP);

  ledcSetup(pwmChannel1, pwmFreq, pwmResolution);
  ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
  ledcSetup(pwmChannel3, pwmFreq, pwmResolution);

  ledcAttachPin(pumpPin, pwmChannel1);
  ledcAttachPin(fanPin, pwmChannel2);
  ledcAttachPin(ledPin, pwmChannel3);


  ledcWrite(pwmChannel3, 0);
  ledcWrite(pwmChannel2, 0);
  ledcWrite(pwmChannel1, 0);


  EEPROM.begin(EEPROM_SIZE);
  brightnessLED = EEPROM.read(0);
  speedFAN = EEPROM.read(1);
  speedPUMP = EEPROM.read(2);
  Controls = EEPROM.read(8);



  xTaskCreate(Task_readKeypadTask, "KeypadTask", 3072, NULL, 4, NULL);

  xTaskCreate(Task_read_temperature, "dhtnhietdo", 2048, NULL, 5, NULL);

  xTaskCreate(Task_read_soil_moisture, "cbdoamdat", 2048, NULL, 6, NULL);
  xTaskCreate(Task_read_light, "cb_anhsang", 2048, NULL, 7, NULL);

  xTaskCreate(Task_readbuttonled, "buttonledTask", 2048, NULL, 1, NULL);
  xTaskCreate(Task_readbuttonfan, "buttonfanTask", 2048, NULL, 2, NULL);
  xTaskCreate(Task_readbuttonpump, "buttonpumpTask", 2048, NULL, 3, NULL);
  lcd.init();  // initialize the lcd
  lcd.backlight();

  function_wifi();



  server.on("/", ketnoi);

  server.on("/kiemtraNT", handlePUSH_NT);
  server.on("/kiemtraDAD", hanlePUSH_DAD);
  server.on("/kiemtraTime", hanlePUSH_Time);
  server.on("/kiemtraCONTROL", handlePUSH_control);
  server.on("/kiemtraIMAGE", handlePUSH_image);

  server.on("/docnhietdo", docdulieunhietdo);
  server.on("/docnhietdoF", docdulieunhietdoF);
  server.on("/docdoam", docdulieudoam);

  //-------------------------------

  server.on("/docdoamdat", docdulieudoamdat);
  server.on("/docanhsang", docdulieuanhsang);

  //---------- goi ham dieu khien button
  // server.on("/docbuttonled", trangthailed);
  // server.on("/docbuttonfan", trangthaifan);
  // server.on("/docbuttonpump", handletrangthaipump);

  // -------------------------------LED
  server.on("/setLED", handleLED);  // as Per  <a href="ledOn">, Subroutine to be called

  //------------------------------FAN
  server.on("/setFAN", handleFAN);  // as Per  <a href="ledOn">, Subroutine to be called

  //--------------------------------PUMP
  server.on("/setPUMP", handlePUMP);  // as Per  <a href="ledOn">, Subroutine to be called

  //----------------------
  server.on("/setKTNT", handlekiemtraNT);
  server.on("/setKTDAD", handlekiemtraDAD);
  server.on("/setTIME", handlekiemtraTime);
  server.on("/setCONTROL", handlekiemtraControl);
  server.on("/setIMAGE", handlekiemtraImage);

  server.begin();
}

void loop() {
  server.handleClient();
}

void Task_readKeypadTask(void *pvParameters) {  // Task to read keypad input



  while (1) {
    char key = keypad.getKey();

    if (key) {
      Serial.println(key);
      if (key == 'A') {
        Serial.println("hien thi trang thai");
        printLCD();
        LCD_setup();
        LCD_sensor();
        save = 0;
      }
      if (key == 'C') {
        lcd.clear();
        save = 1;
        tam = "";
      }
      if (key == 'B') {
        LCD_show();
        Serial.println("hien thi trang thai cai dat");
        save = 0;
      }
      if (save == 1) {
        if (key == '#') {
          if (selection == 0) {
            selection = 1;
          } else if (selection == 1) {
            selection = 2;

          } else {
            selection = 0;
          }
        }
      }

      if (save == 1) {
        if (selection == 0) {
          LCD_speedFAN();
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0') {
            KT = 1;
            if (loca == 18 || loca == 19) {
              lcd.setCursor(loca, 3);  // move cursor to   (cursorColumn, 0)
              lcd.print(key);
            }
            loca++;

            if (loca == 19 || loca == 20) {
              tam += key;
              Serial.println(tam);
              if (loca == 20) {
                lcd.setCursor(18, 3);  // move cursor to   (cursorColumn, 0)
                lcd.print(tam);
              }
            }

            if (loca == 21) {
              lcd.setCursor(0, 3);  // Set cursor to the beginning of the second line
              lcd.print("                    ");
              loca = 18;
              tam = "";
            }
          }
        }

        if (selection == 1) {
          LCD_brightnessLED();
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0') {
            KT = 1;

            if (loca == 18 || loca == 19) {

              lcd.setCursor(loca, 3);  // move cursor to   (cursorColumn, 0)
              lcd.print(key);
            }

            loca++;

            if (loca == 19 || loca == 20) {
              tam += key;
              Serial.println(tam);
              if (loca == 20) {
                lcd.setCursor(18, 3);  // move cursor to   (cursorColumn, 0)
                lcd.print(tam);
              }
            }

            if (loca == 21) {
              lcd.setCursor(0, 3);  // Set cursor to the beginning of the second line
              lcd.print("                    ");
              loca = 18;
              tam = "";
            }
          }
        }

        if (selection == 2) {
          LCD_speedPUMP();
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0') {
            KT = 1;

            if (loca == 18 || loca == 19) {

              lcd.setCursor(loca, 3);  // move cursor to   (cursorColumn, 0)
              lcd.print(key);
            }

            loca++;

            if (loca == 19 || loca == 20) {
              tam += key;
              Serial.println(tam);
              if (loca == 20) {
                lcd.setCursor(18, 3);  // move cursor to   (cursorColumn, 0)
                lcd.print(tam);
              }
            }

            if (loca == 21) {
              lcd.setCursor(0, 3);  // Set cursor to the beginning of the second line
              lcd.print("                    ");
              loca = 18;
              tam = "";
            }
          }
        }

        if (key == 'D') {
          if (selection == 0) {

            if (KT == 1) {
              //speedFAN = tam.toInt();
              speedFAN = map(tam.toInt(), 0, 100, 0, 255);
              EEPROM.write(1, speedFAN);
              EEPROM.commit();
              Serial.print("gia tri cua tam la: ");
              Serial.println(tam);
              Serial.print("gia tri cua SP la: ");
              Serial.println(speedFAN);

              KT = 0;
            }
          }

          if (selection == 1) {

            if (KT == 1) {
              // brightnessLED = tam.toInt();
              brightnessLED = map(tam.toInt(), 0, 100, 0, 255);
              EEPROM.write(0, brightnessLED);
              EEPROM.commit();
              Serial.print("gia tri cua tam la: ");
              Serial.println(tam);
              Serial.print("gia tri cua SP la: ");
              Serial.println(brightnessLED);

              KT = 0;
            }
          }


          if (selection == 2) {

            if (KT == 1) {
              speedPUMP = map(tam.toInt(), 0, 100, 0, 255);
              EEPROM.write(2, speedPUMP);
              EEPROM.commit();
              Serial.print("gia tri cua tam la: ");
              Serial.println(tam);
              Serial.print("gia tri cua SP la: ");
              Serial.println(speedPUMP);

              KT = 0;
            }
          }
        }
      }
    }

    vTaskDelay(100 / portTICK_PERIOD_MS);  // Wait for 100 milliseconds
  }
}

void LCD_setup() {

  Serial.println("Dang o task LCD_setup");

  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);

  lcd.print("GIAM SAT NONG NGHIEP");

  lcd.setCursor(0, 1);
  lcd.print("ND:");
  lcd.setCursor(7, 1);
  lcd.print("C");

  lcd.setCursor(10, 1);
  lcd.print("NDF:");
  lcd.setCursor(18, 1);
  lcd.print("F");

  lcd.setCursor(0, 2);
  lcd.print("DA:");
  lcd.setCursor(7, 2);
  lcd.print("%");

  lcd.setCursor(10, 2);
  lcd.print("DAD:");
  lcd.setCursor(18, 2);
  lcd.print("%");

  lcd.setCursor(4, 3);
  lcd.print("THAS:");
}

void LCD_sensor() {

  lcd.setCursor(3, 1);
  lcd.print(LCDNT);

  lcd.setCursor(14, 1);
  lcd.print(LCDNTF);

  lcd.setCursor(3, 2);
  lcd.print(LCDDA);

  lcd.setCursor(14, 2);
  lcd.print(LCDDAD);

  lcd.setCursor(9, 3);
  lcd.print(LCDAS);
}

void LCD_show() {

  Serial.println("Dang o task LCD_show");
  lcd.clear();

  lcd.backlight();

  lcd.setCursor(4, 0);

  lcd.print("CONTROl SPEED SETTING");

  lcd.setCursor(0, 1);
  lcd.print("BRIGHTNESS LED:");
  lcd.setCursor(16, 1);
  lcd.print(percent(brightnessLED));
  lcd.setCursor(19, 1);
  lcd.print("%");

  lcd.setCursor(0, 2);
  lcd.print("FAN SPEED:");
  lcd.setCursor(12, 2);
  lcd.print(percent(speedFAN));
  lcd.setCursor(14, 2);
  lcd.print("%");

  lcd.setCursor(0, 3);
  lcd.print("PUMP SPEED: ");
  lcd.setCursor(12, 3);
  lcd.print(percent(speedPUMP));
  lcd.setCursor(15, 3);
  lcd.print("%");
}

void LCD_brightnessLED() {

  Serial.println("Dang o task LCD_brightnessLED");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("SETTING POINT PWM");
  lcd.setCursor(4, 1);
  lcd.print("BRIGHTNESS LED");
}

void LCD_speedFAN() {
  Serial.println("Dang o task LCD_speedFAN");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("SETTING POINT PWM");
  lcd.setCursor(3, 1);
  lcd.print("FAN SPEED");
}


void LCD_speedPUMP() {
  Serial.println("Dang o task LCD_speedPUMP");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("SETTING POINT PWM");
  lcd.setCursor(3, 1);
  lcd.print("PUMP SPEED");
}

void printLCD() {
  Serial.println("Dang task home");
  Serial.println("hien thij cac gia tri");
}

void Task_read_soil_moisture(void *pvParameters)  // This is a task.
{


  while (1) {
    // read the input on analog pin A3:
    int sensorValue = analogRead(chancb_dat);
    // print out the value you read:
    doamdat = map(sensorValue, 4095, 2100, 0, 100);  // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100.
    Serial.print("gia tri do am dat: ");
    Serial.println(doamdat);
    Serial.println(sensorValue);

    String spercent = String(doamdat);
    if (doamdat > 110) {
      LCDDAD = "nan";
    } else {
      LCDDAD = spercent;
    }

    vTaskDelay(4000 / portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
  }
}

void Task_read_light(void *pvParameters)  // This is a task.
{


  while (1) {
    // read the input on analog pin A3:
    int sensorValue = analogRead(chancb_anhsang);
    // print out the value you read:
    anhsang = map(sensorValue, 600, 4095, 0, 100);  // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100.
    Serial.print("gia tri anh sang: ");
    Serial.println(anhsang);
    Serial.println(sensorValue);

    String htanhsang;
    if (anhsang > 50) {
      htanhsang = "Dang toi";
    } else {
      htanhsang = "Dang sang";
    }

    if (anhsang < -5) {
      LCDAS = "nan";
    } else {
      LCDAS = anhsang;
    }

    vTaskDelay(4000 / portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
  }
}

void Task_read_temperature(void *pvParameters)  // This is a task.
{


  while (1) {
    // read the input on analog pin A3:
    call_read_temperature();
    call_read_temperature_in_F();
    call_read_Humidit();

    vTaskDelay(4000 / portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
  }
}


void call_read_temperature() {
  nhietdo = dht.readTemperature();
  // print out the value you read:
  Serial.print("gia tri nhiet do: ");
  Serial.println(nhietdo);
  String snhietdo = String(nhietdo);
  if (isnan(nhietdo)) {
    LCDNT = "nan";
  } else {
    LCDNT = snhietdo;
  }
}

void call_read_temperature_in_F() {
  nhietdoF = dht.readTemperature(true);
  // print out the value you read:
  Serial.print("gia tri nhiet do theo F: ");
  Serial.println(nhietdoF);

  String snhietdoF = String(nhietdoF);
  if (isnan(nhietdoF)) {
    LCDNTF = "nan";
  } else {
    LCDNTF = snhietdoF;
  }
}

void call_read_Humidit() {
  doam = dht.readHumidity();
  // print out the value you read:
  Serial.print("gia tri do am: ");
  Serial.println(doam);

  String sdoam = String(doam);
  if (isnan(doam)) {
    LCDDA = "nan";
  } else {
    LCDDA = sdoam;
  }
}

void ketnoi() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}

void docdulieunhietdo() {
  String snhietdo = String(nhietdo);
  if (isnan(nhietdo)) {
    server.send(200, "text/plane", "Failed");
  } else {
    server.send(200, "text/plane", snhietdo);
  }
}

//----------------------------------------------------------------------------------- ham doc gia tri nhiet do theo F
void docdulieunhietdoF() {
  String snhietdoF = String(nhietdoF);
  if (isnan(nhietdoF)) {
    server.send(200, "text/plane", "Failed");
  } else {
    server.send(200, "text/plane", snhietdoF);
  }
}

// ------------------------------------------------------------------------------------- ham doc gia tri do am
void docdulieudoam() {
  String sdoam = String(doam);
  if (isnan(doam)) {
    server.send(200, "text/plane", "Failed");
  } else {
    server.send(200, "text/plane", sdoam);
  }
}
//---------------------------------------------------------------------------------- ham doc gia tri do am dat
void docdulieudoamdat() {

  String spercent = String(doamdat);
  if (doamdat > 110) {
    server.send(200, "text/plane", "Failed");
  } else {

    server.send(200, "text/plane", spercent);
  }
}

// ----------------------------------------------------------------------------------------- ham doc gia tri anh sang
void docdulieuanhsang() {

  String htanhsang;
  if (anhsang > 50) {
    htanhsang = "Dang toi";
  } else {
    htanhsang = "Dang sang";
  }

  if (anhsang < -5) {
    server.send(200, "text/plane", "Failed");
  } else {
    server.send(200, "text/plane", htanhsang);
  }
}
//----------------------------------------------------

// ------------------ ---------------------------------------------------ham dieu khien cac thiet bi

// -------------------------------------------------dieu khien LED
void handleLED() {
  String cled = server.arg("CLED");
  // thled = cled;
  int dk = cled.toInt();

  if (dk == 1) {
    ledcWrite(pwmChannel3, brightnessLED);

  } else {
    ledcWrite(pwmChannel3, 0);
  }

  Serial.print("LED dang o trang thai:");
  Serial.println(dk);

  server.send(200, "text/plane", "");
}

//-------------------------------------------------------------FAN
void handleFAN() {
  String cfan = server.arg("CFAN");
  // thfan = cfan;
  int dk = cfan.toInt();
  if (dk == 1) {
    ledcWrite(pwmChannel2, speedFAN);

  } else {
    ledcWrite(pwmChannel2, 0);
  }


  Serial.print("FAN dang o trang thai:");
  Serial.println(dk);

  server.send(200, "text/plane", "");
}

//-----------------------------------------------------------------PUMP

void handlePUMP() {
  String cpump = server.arg("CPUMP");
  // thpump = cpump;
  int dk = cpump.toInt();
  if (dk == 1) {
    ledcWrite(pwmChannel1, speedPUMP);

  } else {
    ledcWrite(pwmChannel1, 0);
  }

  Serial.print("PUMP dang o trang thai:");
  Serial.println(dk);

  server.send(200, "text/plane", "");
}

//-----------------------------------------------------------

void handlekiemtraNT() {
  String KTNT = server.arg("KTNT");
  int percent = KTNT.toInt();

  brightnessLED = map(percent, 0, 100, 0, 255);

  EEPROM.write(0, brightnessLED);
  EEPROM.commit();

  delay(60);
  Serial.print("Dieu kien kiem tra nhiet do: ");
  Serial.println(brightnessLED);

  server.send(200, "text/plane", "");
}

void handlekiemtraDAD() {
  String KTDAD = server.arg("KTDAD");
  int percent = KTDAD.toInt();
  speedFAN = map(percent, 0, 100, 0, 255);

  EEPROM.write(1, speedFAN);
  EEPROM.commit();

  delay(60);
  Serial.print("Dieu kien kiem tra do am dat: ");
  Serial.println(speedFAN);

  server.send(200, "text/plane", "");
}

void handlekiemtraTime() {
  String takeTIMES = server.arg("TIME");
  int percent = takeTIMES.toInt();
  speedPUMP = map(percent, 0, 100, 0, 255);
  EEPROM.write(2, speedPUMP);
  EEPROM.commit();


  //EEPROM.write(4, TimeBD);
  //EEPROM.commit();


  delay(60);
  Serial.print("Chon thoi gian lay du lieu la: ");
  Serial.println(speedPUMP);

  server.send(200, "text/plane", "");
}

void handlekiemtraControl() {
  String takeControl = server.arg("CONTROL");
  Controls = takeControl.toInt();
  EEPROM.write(8, Controls);
  EEPROM.commit();

  delay(60);
  Serial.print("Chon che do dieu khien la: ");
  Serial.println(Controls);

  server.send(200, "text/plane", "");
}

void handlekiemtraImage() {
  image = server.arg("IMAGE");
  writeStringToEEPROM(image);
  delay(60);
  Serial.print("link hinh anh gui ve la: ");
  Serial.println(image);

  server.send(200, "text/plane", "");
}

void handlePUSH_NT() {
  String sNT = String(percent(brightnessLED));

  server.send(200, "text/plane", sNT);
}

void hanlePUSH_DAD() {
  String sDAD = String(percent(speedFAN));

  server.send(200, "text/plane", sDAD);
}

void hanlePUSH_Time() {

  String pushTIME = String(percent(speedPUMP));

  server.send(200, "text/plane", pushTIME);
}

void handlePUSH_control() {
  String chcontrol = String(Controls);

  server.send(200, "text/plane", chcontrol);
}

void handlePUSH_image() {
  image = readStringFromEEPROM();
  server.send(200, "text/plane", image);
}

void function_wifi() {
  WiFi.mode(WIFI_STA);
  WiFiManager wm;

  // reset settings - wipe stored credentials for testing
  // these are stored by the esp library

  //  wm.resetSettings();

  // Automatically connect using saved credentials,
  // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
  // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
  // then goes into a blocking loop awaiting configuration and will return success result

  bool res;
  // res = wm.autoConnect(); // auto generated AP name from chipid
  // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
  res = wm.autoConnect("AutoConnectAP", "password");  // password protected ap

  if (!res) {
    Serial.println("Failed to connect");
    // ESP.restart();
  } else {
    // if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");

    Serial.println("dia chi IP: ");
    Serial.println(WiFi.localIP());
  }
}


void Task_readbuttonled(void *pvParameters) {  // Task to read keypad input


  while (1) {
    if (Controls == 0) {


      if (digitalRead(buttonled) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonled) == 0) {
          if (onOffled == 0) {
            onOffled = 1;
            ledcWrite(pwmChannel3, brightnessLED);

          } else {
            onOffled = 0;
            ledcWrite(pwmChannel3, 0);
          }
        }
        while (digitalRead(buttonled) == 0)
          ;
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);  // Wait for 100 milliseconds
  }
}

void Task_readbuttonfan(void *pvParameters) {  // Task to read keypad input


  while (1) {
    if (Controls == 0) {
      if (digitalRead(buttonfan) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonfan) == 0) {
          if (onOfffan == 0) {
            onOfffan = 1;
            ledcWrite(pwmChannel2, speedFAN);

          } else {
            onOfffan = 0;
            ledcWrite(pwmChannel2, 0);
          }
        }
        while (digitalRead(buttonfan) == 0)
          ;
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);  // Wait for 100 milliseconds
  }
}

void Task_readbuttonpump(void *pvParameters) {  // Task to read keypad input


  while (1) {
    if (Controls == 0) {

      if (digitalRead(buttonpump) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonpump) == 0) {
          if (onOffpump == 0) {
            onOffpump = 1;
            ledcWrite(pwmChannel1, speedPUMP);


          } else {
            onOffpump = 0;
            ledcWrite(pwmChannel1, 0);
          }
        }
        while (digitalRead(buttonpump) == 0)
          ;
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);  // Wait for 100 milliseconds
  }
}

void writeStringToEEPROM(const String &data) {
  int len = data.length();
  for (int i = 0; i < len; ++i) {
    EEPROM.write(EEPROM_ADDR + i, data[i]);
  }
  // Add null terminator at the end of the string
  EEPROM.write(EEPROM_ADDR + len, '\0');
  EEPROM.commit();  // Save the changes to the EEPROM
}

String readStringFromEEPROM() {
  char buffer[EEPROM_SIZE];
  int i;
  for (i = 0; i < EEPROM_SIZE; ++i) {
    char c = EEPROM.read(EEPROM_ADDR + i);
    if (c == '\0') {
      break;
    }
    buffer[i] = c;
  }
  buffer[i] = '\0';

  return String(buffer);
}
/*
void writeIntToEEPROM(int data) {
  EEPROM.write(4, (data >> 8) & 0xFF);  // Most significant byte (MSB)
  EEPROM.write(5, data & 0xFF);         // Least significant byte (LSB)
  EEPROM.commit();                      // Save the changes to the EEPROM
}

int readIntFromEEPROM() {
  int msb = EEPROM.read(4);
  int lsb = EEPROM.read(5);
  return (msb << 8) | lsb;
}*/

int percent(int value) {
  return (int)((value * 100) / 255);
}
