#include <stdio.h>
#include "BMS_Receiver.h"
#include "BMS_Sender.h"

StatusType ReceiveDataFromConsole(ReceiverBatteryParameterInfo  *parameterInfo)
{
 
  int index;
  int inner_index;
  for(index=0;index<Number_of_values;index++)
  {
    for(inner_index=0; inner_index<NoOfParameter-1; inner_index++)
    {
       scanf("%f",&parameterInfo[index].parameterdata[inner_index]);
    }
    scanf("%f",&parameterInfo[index].parameterdata[inner_index]);
  }
 return E_OK;
}

float GetMaxValueOfIncomingStream(float *ParameterInfo)
{
 float MaxValue = ParameterInfo[0];
 
  return MaxValue;
}

float GetMinValueofIncomingStream(float *ParameterInfo)
{
  float MinValue = ParameterInfo[0];
 
  return MinValue;
}

void BMSReceiver(ReceiverBatteryParameterInfo  *parameterInfo)
{

  ReceiveDataFromConsole(parameterInfo);
}
