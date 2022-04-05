#include <time.h>
#include <stdlib.h>

float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  srand(time(0));
  float data = (rand() % (int)(maximumThreshold+1)) ;
  if(data < minimumThreshold)
  {
    data = data + minimumThreshold;
  }
  return data;
}


float (*funp_ReadDataFromSensor)() = SimulateReadDataFromSensor;
