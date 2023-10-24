
#define ledPin 18
#define fanPin 17
#define pumpPin 16



int pwmChannel1 = 0;    // PWM channel for pin 16
int pwmChannel2 = 1;    // PWM channel for pin 17
int pwmChannel3 = 2;    // PWM channel for pin 18
int pwmFreq = 5000;     // Frequency in Hz
int pwmResolution = 8;  // Resolution in bits (1-16)

void setup() {
  // Initialize PWM on pins 16, 17, and 18
  ledcSetup(pwmChannel1, pwmFreq, pwmResolution);
  ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
  ledcSetup(pwmChannel3, pwmFreq, pwmResolution);

  ledcAttachPin(pumpPin, pwmChannel1);
  ledcAttachPin(fanPin, pwmChannel2);
  ledcAttachPin(ledPin, pwmChannel3);
}

void loop() {
  // Set different duty cycles for each pin
  

  for (int val = 0; val <= 255; val += 20) {
    ledcWrite(pwmChannel3, val);
    delay(500);
  }

  for(int val = 0; val <= 255; val+= 20){
    ledcWrite(pwmChannel2, val);
    delay(500);
  }

  for(int val = 0; val <= 255; val+= 20){
    ledcWrite(pwmChannel1, val);
    delay(500);
  }

  
}
