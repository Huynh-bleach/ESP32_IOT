#ifndef kalman_h
#define kalman_h
#include <SimpleKalmanFilter.h>



SimpleKalmanFilter bo_loc(2, 2, 0.001);

float kalman(int analog){
  
  randomSeed(millis());
  float  e = (float)random(-10, 10);
  float s = analog + e;
  
  return bo_loc.updateEstimate(s);
}

#endif
