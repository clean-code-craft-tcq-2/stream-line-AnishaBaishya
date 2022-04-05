#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BMS_Sender.h"


int SenderData(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender, float (*funp_ReadDataFromSensor)(float,float)) {
  int index;
  int inner_index;
  for(index=0; index<DataFromSender->number_of_values; index++)
  {
    for(inner_index=0; inner_index<NoOfParameter; inner_index++)
    {
      parameterInfo[inner_index].parameterdata[index] = funp_ReadDataFromSensor(parameterInfo[inner_index].minimumThreshold,parameterInfo[inner_index].maximumThreshold);
    }
  }
  DisplaySensorDataOnConsole(parameterInfo ,DataFromSender);
  return 1;
}

void DisplaySensorDataOnConsole(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender)
{
  int index;
  int inner_index;
  char buf[20];
  for(index=0;index<DataFromSender->number_of_values;index++)
  {
    for(inner_index=0; inner_index<NoOfParameter-1; inner_index++)
    {
      printf("%f ,",parameterInfo[inner_index].parameterdata[index]);
    }
    printf("%f \n",parameterInfo[NoOfParameter-1].parameterdata[index]);
  }
}
}
