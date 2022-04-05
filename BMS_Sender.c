#include "BMS_Sender.h"


int SenderData(BatteryParameterInfo *parameterInfo ,Sender DataFromSender, float (*funp_ReadDataFromSensor)()) {
  int index;
  int inner_index;
  for(index=0; index<DataFromSender.number_of_values; index++)
  {
    for(inner_index=0; inner_index<NoOfParameter; inner_index++)
    {
      parameterInfo[inner_index].parameterdata[index] = funp_ReadDataFromSensor();
    }
  }
  return 1;
}
