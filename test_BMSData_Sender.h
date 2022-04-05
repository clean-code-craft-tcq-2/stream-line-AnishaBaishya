#include <stdlib.h>
#include <time.h>
  
float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  float data = (rand() % (int)(maximumThreshold - minimumThreshold +1)) + minimumThreshold ;
  return data;
}


float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor;
