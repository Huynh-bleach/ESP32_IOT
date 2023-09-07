#include <EEPROM.h>


#define EEPROM_SIZE 100
#define ledPin 18
#define fanPin 17
#define pumpPin 16

#define buttonled 15
#define buttonfan 2
#define buttonpump 4


unsigned char onOffled = 0;
unsigned char onOfffan = 0;
unsigned char onOffpump = 0;
int Controls = 1;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

    pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  pinMode(buttonled, INPUT_PULLUP);
  pinMode(buttonfan, INPUT_PULLUP);
  pinMode(buttonpump, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);
  digitalWrite(fanPin, LOW);
  digitalWrite(pumpPin, LOW);

   
    Serial.print("gia tri tin hieu dieu khien la: ");
    Serial.println(Controls);

  
  xTaskCreatePinnedToCore(Task_readbuttonled, "buttonledTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonfan, "buttonfanTask", 1024, NULL, 5, NULL, 1);
  xTaskCreatePinnedToCore(Task_readbuttonpump, "buttonpumpTask", 1024, NULL, 5, NULL, 1);

  xTaskCreatePinnedToCore(change_button, "change_button", 1024, NULL, 5, NULL, 1);


}

void loop() {
  // put your main code here, to run repeatedly:

  

}




void Task_readbuttonled(void *pvParameters)
{ // Task to read keypad input

  (void)pvParameters;
  for (;;)
  {
   if(Controls == 0){
    
   
    if (digitalRead(buttonled) == 0)
    {
      vTaskDelay(pdMS_TO_TICKS(20));
      if (digitalRead(buttonled) == 0)
      {
        if (onOffled == 0)
        {
          onOffled = 1;
          digitalWrite(ledPin, 1);
        }
        else
        {
          onOffled = 0;
          digitalWrite(ledPin, 0);
        }
      }
      while (digitalRead(buttonled) == 0)
        ;
    }
   
   }
    vTaskDelay(pdMS_TO_TICKS(100)); // Wait for 100 milliseconds
  }
}

void Task_readbuttonfan(void *pvParameters)
{ // Task to read keypad input

  (void)pvParameters;
  for (;;)
  {
if(Controls == 0){
    if (digitalRead(buttonfan) == 0)
    {
      vTaskDelay(pdMS_TO_TICKS(20));
      if (digitalRead(buttonfan) == 0)
      {
        if (onOfffan == 0)
        {
          onOfffan = 1;
          digitalWrite(fanPin, 1);
        }
        else
        {
          onOfffan = 0;
          digitalWrite(fanPin, 0);
        }
      }
      while (digitalRead(buttonfan) == 0)
        ;
    }
    
  }
  vTaskDelay(pdMS_TO_TICKS(100)); // Wait for 100 milliseconds
  }
}

void Task_readbuttonpump(void *pvParameters)
{ // Task to read keypad input

  (void)pvParameters;
  for (;;)
  {
if(Controls == 0){
    if (digitalRead(buttonpump) == 0)
    {
      vTaskDelay(pdMS_TO_TICKS(20));
      if (digitalRead(buttonpump) == 0)
      {
        if (onOffpump == 0)
        {
          onOffpump = 1;
          digitalWrite(pumpPin, 1);
        }
        else
        {
          onOffpump = 0;
          digitalWrite(pumpPin, 0);
        }
      }
      while (digitalRead(buttonpump) == 0)
        ;
    }
    
  }
  vTaskDelay(pdMS_TO_TICKS(100)); // Wait for 100 milliseconds
  }
}

void change_button(void *pvParameters){
   (void)pvParameters;
   for(;;){
     Controls = !Controls; 
Serial.print("gia tri tin hieu dieu khien la: ");
    Serial.println(Controls);
     vTaskDelay(pdMS_TO_TICKS(10000)); 
     
   }
}
