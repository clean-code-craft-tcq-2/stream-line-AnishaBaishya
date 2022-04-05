#include <time.h>
#include <stdlib.h>

float SimulateReadDataFromSensor()
{
  srand(time(0));
  float data = (rand() % (int)(100)) ;
  return data;
}


float (*funp_ReadDataFromSensor)() = SimulateReadDataFromSensor;
