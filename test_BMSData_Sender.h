#include <time.h>
#include <stdlib.h>

float GenerateRandomSensorValue(float minimumThreshold,float maximumThreshold)
{
  float data = (rand() % (int)(maximumThreshold - minimumThreshold +1)) + minimumThreshold ;
  return data;
}

float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  float data = GenerateRandomSensorValue(minimumThreshold,maximumThreshold);
  return data;
}


float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor;
