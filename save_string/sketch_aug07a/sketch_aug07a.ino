#include <EEPROM.h>

// Define the size of the string to be saved
const int EEPROM_SIZE = 100;

// Address in the EEPROM where the string will be stored (starting from 10th cell)
const int EEPROM_ADDR = 10;

void setup() {
  // Start the EEPROM library
  EEPROM.begin(EEPROM_SIZE);

  // Write the string to the EEPROM
  writeStringToEEPROM("https://gamen.vn/storage/2022/10/Bleach-Thousand-Year-Blood-War-Feature.jpg");

  // Read the string back from the EEPROM and print it
  String savedString = readStringFromEEPROM();
  Serial.begin(115200);
  Serial.println("String read from EEPROM: " + savedString);
}

void loop() {
  // Your code here
}

void writeStringToEEPROM(const String &data) {
  int len = data.length();
  for (int i = 0; i < len; ++i) {
    EEPROM.write(EEPROM_ADDR + i, data[i]);
  }
  // Add null terminator at the end of the string
  EEPROM.write(EEPROM_ADDR + len, '\0');
  EEPROM.commit(); // Save the changes to the EEPROM
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
