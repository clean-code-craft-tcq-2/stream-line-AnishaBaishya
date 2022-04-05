#include <time.h>
#include <stdlib.h>

float ReadDataFromSensor()
{
  srand(time(0));
  float data = (rand() % (int)(100)) ;
  return data;
}


float (*funp_ReadDataFromSensor)() = ReadDataFromSensor;
