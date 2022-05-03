#include <stdio.h>
#include "BMS_Receiver.h"
#include "BMS_Sender.h"

StatusType ReceiveDataFromConsole(float  *TemperatureData, float *SOC_Data, float *ChargeRateData)
{
 
  int index;
  for(index = 0; index < INCOMING_STRAEM_SIZE; index++)
  {
    scanf("%f ,%f ,%f",&TemperatureData[index],&SOC_Data[index],&ChargeRateData[index]);
  }
 return E_OK;
}

float GetMaxValueOfIncomingStream(float *ParameterData)
{
 float MaxValue = ParameterData[0]; 
 int Index;
    for(Index = 0; Index < INCOMING_STRAEM_SIZE; Index++)
   {
     if(ParameterData[Index] > MaxValue)
     {
       MaxValue = ParameterData[Index];
     }
   }
  return MaxValue;
}

float GetMinValueofIncomingStream(float *ParameterData)
{
  float MinValue = ParameterData[0];
 
  return MinValue;
}

void BMSReceiver(float  *ParameterData)
{
  GetMaxValueOfIncomingStream(ParameterData);
}
