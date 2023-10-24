#include <Arduino.h>
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
void Task_readbuttonled(void *pvParameters);
void Task_readbuttonfan(void *pvParameters);
void Task_readbuttonpump(void *pvParameters);

void setup() {
  // put your setup code here, to run once:


  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  pinMode(buttonled, INPUT_PULLUP);
  pinMode(buttonfan, INPUT_PULLUP);
  pinMode(buttonpump, INPUT_PULLUP);

  EEPROM.begin(EEPROM_SIZE);

  onOffled = EEPROM.read(3);
  onOfffan = EEPROM.read(4);
  onOffpump = EEPROM.read(5);

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


  xTaskCreatePinnedToCore(Task_readbuttonled, "buttonledTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonfan, "buttonfanTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonpump, "buttonpumpTask", 1024, NULL, 5, NULL, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
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
