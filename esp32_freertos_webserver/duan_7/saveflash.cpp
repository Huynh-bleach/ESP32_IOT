#include "saveflash.h"
#include "define.h"
#include <EEPROM.h>

void writeIntToEEPROM(int data) {
  EEPROM.write(EEPROM_ADDR, (data >> 8) & 0xFF);  // Most significant byte (MSB)
  EEPROM.write(EEPROM_ADDR + 1, data & 0xFF);     // Least significant byte (LSB)
  EEPROM.commit(); // Save the changes to the EEPROM
}

int readIntFromEEPROM() {
  int msb = EEPROM.read(EEPROM_ADDR);
  int lsb = EEPROM.read(EEPROM_ADDR + 1);
  return (msb << 8) | lsb;
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
