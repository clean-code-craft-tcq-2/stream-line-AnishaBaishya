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
  formatSensorData(parameterInfo ,DataFromSender);
  printonConsole(DataFromSender);
  return 1;
}

void formatSensorData(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender)
{
  int index;
  int inner_index;
  char buf[20];
  for(index=0;index<DataFromSender->number_of_values;index++)
  {
    for(inner_index=0; inner_index<NoOfParameter-1; inner_index++)
    {
      gcvt(parameterInfo[inner_index].parameterdata[index], 6, buf);
      strcat(&buf ,",");
      strcpy(*DataFromSender->formatted_senderdata[index],buf);
    }
    gcvt(parameterInfo[NoOfParameter-1].parameterdata[index], 6, buf);
    strcat(*DataFromSender->formatted_senderdata[index] , buf);
  }
}

void printonConsole(Sender *DataFromSender)
{
  int index;
  for(int index=0;index<DataFromSender->number_of_values;index++)
  {
    printf ("%s",DataFromSender->formatted_senderdata[index]);
  }
}
