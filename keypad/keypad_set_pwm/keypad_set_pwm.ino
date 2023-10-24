#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

#define EEPROM_SIZE 100

#define EEPROM_ADDR 10


#define ledPin 18
#define fanPin 17
#define pumpPin 16


#define buttonled 15
#define buttonfan 2
#define buttonpump 4


int onOffled = 0;
int onOfffan = 0;
int onOffpump = 0;

int Controls = 0;

String LCDNT;
String LCDNTF;
String LCDDA;
String LCDDAD;
String LCDAS;



int save = 0;
int loca = 18;
int speedFAN = 30;
int brightnessLED = 50;
int speedPUMP = 10;
String tam;
int KT;
int selection = 0;





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


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  pinMode(buttonled, INPUT_PULLUP);
  pinMode(buttonfan, INPUT_PULLUP);
  pinMode(buttonpump, INPUT_PULLUP);

  
  EEPROM.begin(EEPROM_SIZE);

  brightnessLED = EEPROM.read(0);
  speedFAN = EEPROM.read(1);
  speedPUMP = EEPROM.read(2);


  if (onOffled == 0) {
    digitalWrite(ledPin, 0);
  } else {
    digitalWrite(ledPin, 1);
  }


  if (onOfffan == 0) {
    digitalWrite(fanPin, 0);
  } else {
    digitalWrite(fanPin, 1);
  }


  if (onOffpump == 0) {
    digitalWrite(pumpPin, 0);
  } else {
    digitalWrite(pumpPin, 1);
  }



  xTaskCreatePinnedToCore(Task_readKeypadTask, "KeypadTask", 2048, NULL, 5, NULL, 1);

 xTaskCreatePinnedToCore(Task_readbuttonled, "buttonledTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonfan, "buttonfanTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonpump, "buttonpumpTask", 1024, NULL, 5, NULL, 1);
  lcd.init();  // initialize the lcd
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
}


void Task_readKeypadTask(void *pvParameters) {  // Task to read keypad input

  (void)pvParameters;

  for (;;) {
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
          if(selection == 0){
            selection = 1;
          }
          else if(selection == 1){
            selection = 2;

          }
          else{
            selection = 0;
          }
        }
      }

      if (save == 1) {
        if (selection == 0) {
          LCD_speedFAN();
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9'||key == '0') {
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
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9'||key == '0') {
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
          if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9'||key == '0') {
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
              speedFAN = tam.toInt();
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
              brightnessLED = tam.toInt();
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
              speedPUMP = tam.toInt();
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

    vTaskDelay(pdMS_TO_TICKS(100));  // Wait for 100 milliseconds
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
  lcd.print(brightnessLED);
  lcd.setCursor(18, 1);
  lcd.print("%");

  lcd.setCursor(0, 2);
  lcd.print("FAN SPEED:");
  lcd.setCursor(12, 2);
  lcd.print(speedFAN);
  lcd.setCursor(14, 2);
  lcd.print("%");

  lcd.setCursor(0, 3);
  lcd.print("PUMP SPEED: ");
  lcd.setCursor(12, 3);
  lcd.print(speedPUMP);
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



void Task_readbuttonled(void *pvParameters) {  // Task to read keypad input

  (void)pvParameters;
  for (;;) {
    if (Controls == 0) {


      if (digitalRead(buttonled) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonled) == 0) {
          if (onOffled == 0) {
            onOffled = 1;
            digitalWrite(ledPin, 1);
            
            
          } else {
            onOffled = 0;
            digitalWrite(ledPin, 0);
            
           
          }
        }
        while (digitalRead(buttonled) == 0)
          ;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100));  // Wait for 100 milliseconds
  }
}

void Task_readbuttonfan(void *pvParameters) {  // Task to read keypad input

  (void)pvParameters;
  for (;;) {
    if (Controls == 0) {
      if (digitalRead(buttonfan) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonfan) == 0) {
          if (onOfffan == 0) {
            onOfffan = 1;
            digitalWrite(fanPin, 1);
          } else {
            onOfffan = 0;
            digitalWrite(fanPin, 0);
          }
        }
        while (digitalRead(buttonfan) == 0)
          ;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100));  // Wait for 100 milliseconds
  }
}

void Task_readbuttonpump(void *pvParameters) {  // Task to read keypad input

  (void)pvParameters;
  for (;;) {
    if (Controls == 0) {
      
      if (digitalRead(buttonpump) == 0) {
        vTaskDelay(pdMS_TO_TICKS(20));
        if (digitalRead(buttonpump) == 0) {
          if (onOffpump == 0) {
            onOffpump = 1;
            digitalWrite(pumpPin, 1);
      
          } else {
            onOffpump = 0;
            digitalWrite(pumpPin, 0);
          }
        }
        while (digitalRead(buttonpump) == 0)
          ;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100));  // Wait for 100 milliseconds
  }
}




