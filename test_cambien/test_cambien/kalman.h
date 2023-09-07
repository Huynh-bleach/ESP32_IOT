#ifndef kalman_h
#define kalman_h
#include <SimpleKalmanFilter.h>



SimpleKalmanFilter bo_loc(2, 2, 0.001);

float kalman(int analog){
  
  randomSeed(millis());
  float  e = (float)random(-100, 100);
  float s = analog + e;

  float occur = bo_loc.updateEstimate(s);

  



  
  return occur;
}

#endif
