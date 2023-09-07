#ifndef saveflash_h
#define savedlash_h
#include <Arduino.h>
#include "define.h"


void writeIntToEEPROM(int data);
void writeStringToEEPROM(const String &data);
int readIntFromEEPROM();
String readStringFromEEPROM(); 


#endif
