#include <Keypad.h>
 #include <EEPROM.h>


#include <LiquidCrystal_I2C.h>



#define EEPROM_SIZE 4







String LCDNT;
String LCDNTF;
String LCDDA;
String LCDDAD;
String LCDAS;

 
 int save = 0;
  int loca = 18;
  int setDAD = 30;
  int setNT = 50;
  int TimeBD  = 10;
  String tam;
  int KT;
  int selection = 0;



#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {32, 33, 25, 26}; // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte pin_column[COLUMN_NUM] = {27, 14, 12, 13};   // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 20, 4); // I2C address 0x27, 16 column and 2 rows

int cursorColumn = 0;


void LCD_setup();
void LCD_sensor();
void LCD_show();
void LCD_setNT();
void LCD_setDAD();







void setup() {

    Serial.begin(9600);

   EEPROM.begin(EEPROM_SIZE);
   setNT = EEPROM.read(0);
   setDAD = EEPROM.read(1);
   TimeBD = EEPROM.read(4);

   
  lcd.init(); // initialize the lcd
  lcd.backlight();
  // put your setup code here, to run once:
xTaskCreatePinnedToCore(Task_readKeypadTask, "KeypadTask", 2048, NULL, 5, NULL,1);

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.begin(9600);

   EEPROM.begin(EEPROM_SIZE);
   setNT = EEPROM.read(0);
   setDAD = EEPROM.read(1);
   TimeBD = EEPROM.read(4);

}


void Task_readKeypadTask(void *pvParameters) { // Task to read keypad input

  (void)pvParameters;
  
  for (;;) {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
     if(key == 'A'){
      Serial.println("hien thi trang thai");
     printLCD();
     LCD_setup();
    // LCD_sensor();
     save = 0;
    }
    if(key == 'C'){
      lcd.clear();
      save = 1;
      tam = "";
    }
    if(key == 'B'){
      LCD_show();
      Serial.println("hien thi trang thai cai dat");
      save = 0;
    }
     if(save == 1){
      if(key == '#'){
        selection = !selection;
      }
     }
    
    if( save == 1){
      if(selection == 0){
        LCD_setDAD();
      if( key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' ||key == '7' || key == '8' ||key == '9'){
       KT = 1;
        if(loca == 18 || loca == 19){
       lcd.setCursor(loca, 3); // move cursor to   (cursorColumn, 0)
       lcd.print(key);
        }
       loca++;
       
       if(loca == 19 || loca == 20){
          tam += key;
          Serial.println(tam);
            if(loca == 20){
            lcd.setCursor(18, 3); // move cursor to   (cursorColumn, 0)
            lcd.print(tam);
          }
       }

       
       if(loca == 21){
        lcd.setCursor(0, 3); // Set cursor to the beginning of the second line
        lcd.print("                    "); 
        loca = 18;
        tam = "";
       }
      }
      }

      if(selection == 1){
        LCD_setNT();
      if( key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' ||key == '7' || key == '8' ||key == '9'){
       KT = 1;

         if(loca == 18 || loca == 19){
       
         lcd.setCursor(loca, 3); // move cursor to   (cursorColumn, 0)
         lcd.print(key);
         }
          
       loca++;
       
       if(loca == 19 || loca == 20){
          tam += key;
          Serial.println(tam);
          if(loca == 20){
            lcd.setCursor(18, 3); // move cursor to   (cursorColumn, 0)
            lcd.print(tam);
          }
          
       }

       
       if(loca == 21){
        lcd.setCursor(0, 3); // Set cursor to the beginning of the second line
        lcd.print("                    "); 
        loca = 18;
        tam = "";
       }
      }
      }
      
      if(key == 'D'){
         if(selection == 0){
           
        if(KT == 1){
          setDAD = tam.toInt();
            EEPROM.write(1, setDAD);
            EEPROM.commit();
        Serial.print("gia tri cua tam la: ");
        Serial.println(tam);
        Serial.print("gia tri cua SP la: ");
        Serial.println(setDAD);

        KT = 0;
        
        }
         }


        if(selection == 1){
           
        if(KT == 1){
        setNT = tam.toInt();
       EEPROM.write(0, setNT);
        EEPROM.commit();
        Serial.print("gia tri cua tam la: ");
        Serial.println(tam);
        Serial.print("gia tri cua SP la: ");
        Serial.println(setDAD);

        KT = 0;
        
        }
         }
       
      }
    }
  }

    vTaskDelay(pdMS_TO_TICKS(100)); // Wait for 100 milliseconds
  }
}





void LCD_setup(){

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
/*
void LCD_sensor(){
 
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
*/
void LCD_show(){

   Serial.println("Dang o task LCD_show");
  lcd.clear();
      
  lcd.backlight();

  lcd.setCursor(4, 0);

  lcd.print("SET POINTS");

  lcd.setCursor(0, 1);
  lcd.print("SET POINT NT:");
   lcd.setCursor(15, 1);
  lcd.print(setNT);
  lcd.setCursor(17, 1);
  lcd.print("C");

  lcd.setCursor(0, 2);
  lcd.print("SET POINT DAD:");
   lcd.setCursor(15, 2);
  lcd.print(setDAD);
  lcd.setCursor(17, 2);
  lcd.print("%");

  lcd.setCursor(0, 3);
  lcd.print("ACTIVE STATUS:");



  
}


void LCD_setNT(){

   Serial.println("Dang o task LCD_setNT");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("SETTING SET POINT");
  lcd.setCursor(4,1);
  lcd.print("TEMPERATURE");
}

void LCD_setDAD(){
   Serial.println("Dang o task LCD_setDAD");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("SETTING SET POINT");
  lcd.setCursor(3,1);
  lcd.print("SOIL MOISTURE");
}


void printLCD(){
  Serial.println("Dang task home");
  Serial.println("hien thij cac gia tri");
}
