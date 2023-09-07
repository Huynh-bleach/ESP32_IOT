#include <DHT.h>

#include "kalman.h"

#define chancb_dat 35
#define chancb_anhsang 39
#define chandht 23
#define loaidht DHT11


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

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(chandht, INPUT);

  pinMode(chancb_anhsang, INPUT);

  pinMode(chancb_dat, INPUT);
  dht.begin();

  
  xTaskCreatePinnedToCore(Task_read_temperature, "dhtnhietdo", 1024, NULL, 5, NULL, 1);

  xTaskCreatePinnedToCore(Task_read_soil_moisture, "cbdoamdat", 1024, NULL, 4, NULL, 1);
  xTaskCreatePinnedToCore(Task_read_light, "cb_anhsang", 2048, NULL, 4, NULL, 0);


}

void loop() {
  // put your main code here, to run repeatedly:

}




void Task_read_soil_moisture(void *pvParameters) // This is a task.
{
  (void)pvParameters;

  for (;;)
  {
    // read the input on analog pin A3:
    int sensorValue = analogRead(chancb_dat);
    // print out the value you read:
    sensorValue = kalman(sensorValue);
    doamdat = map(sensorValue, 4095, 1700, 0, 100); // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100.
    Serial.print("gia tri do am dat: ");
    Serial.println(doamdat);
    Serial.println(sensorValue);

    String spercent = String(doamdat);
    if (doamdat > 110)
    {
      LCDDAD = "nan";
    }
    else
    {
      LCDDAD = spercent;
    }

    vTaskDelay(4000); // one tick delay (15ms) in between reads for stability
  }
}

void Task_read_light(void *pvParameters) // This is a task.
{
  (void)pvParameters;

  for (;;)
  {
    // read the input on analog pin A3:
    int sensorValue = analogRead(chancb_anhsang);
    // print out the value you read:
    sensorValue = kalman(sensorValue);
    anhsang = map(sensorValue, 1000, 4095, 0, 100); // Set giá thang giá trị đầu và giá trị cuối để đưa giá trị về thang từ 0-100.
    Serial.print("gia tri anh sang: ");
    Serial.println(anhsang);
    Serial.println(sensorValue);

    String htanhsang;
    if (anhsang > 50)
    {
      htanhsang = "Dang toi";
    }
    else
    {
      htanhsang = "Dang sang";
    }

    if (anhsang < -5)
    {
      LCDAS = "nan";
    }
    else
    {
      LCDAS = anhsang;
    }

    vTaskDelay(4000); // one tick delay (15ms) in between reads for stability
  }
}

void Task_read_temperature(void *pvParameters) // This is a task.
{
  (void)pvParameters;

  for (;;)
  {
    // read the input on analog pin A3:
    call_read_temperature();
    call_read_temperature_in_F();
    call_read_Humidit();

    vTaskDelay(4000); // one tick delay (15ms) in between reads for stability
  }
}

void call_read_temperature()
{
  nhietdo = dht.readTemperature();
  // print out the value you read:
  Serial.print("gia tri nhiet do: ");
  Serial.println(nhietdo);
  String snhietdo = String(nhietdo);
  if (isnan(nhietdo))
  {
    LCDNT = "nan";
  }
  else
  {
    LCDNT = snhietdo;
  }
}

void call_read_temperature_in_F()
{
  nhietdoF = dht.readTemperature(true);
  // print out the value you read:
  Serial.print("gia tri nhiet do theo F: ");
  Serial.println(nhietdoF);

  String snhietdoF = String(nhietdoF);
  if (isnan(nhietdoF))
  {
    LCDNTF = "nan";
  }
  else
  {
    LCDNTF = snhietdoF;
  }
}

void call_read_Humidit()
{
  doam = dht.readHumidity();
  // print out the value you read:
  Serial.print("gia tri do am: ");
  Serial.println(doam);

  String sdoam = String(doam);
  if (isnan(doam))
  {
    LCDDA = "nan";
  }
  else
  {
    LCDDA = sdoam;
  }
}

/*
void ConditionHandlingToControlDevice(int GpioControl, float &variable, String ){
  if( variable > (float)setNT){
    
  }
}
*/
