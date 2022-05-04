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
  int Index;
     for(Index = 0; Index < INCOMING_STRAEM_SIZE; Index++)
   {
     if(ParameterData[Index] < MinValue)
     {
       MinValue = ParameterData[Index];
     }
   }
  return MinValue;
}

float GetSMAofIncomingStream(float *ParameterData, int WindowSize)
{
  float SMA = 0; //Simple Moving Average
  float SumOfValuesInWindow = 0;
  int Index;
 
 for (Index = 0; Index < WindowSize; Index++)
    {
        SumOfValuesInWindow += ParameterData[INCOMING_STRAEM_SIZE-Index-1];
    }
  SMA = (SumOfValuesInWindow / (float)WindowSize);
 
  return SMA;
}

void PrintReceiverDataOnConsole(float *ParameterData, float MaxValue, float MinValue, float SMA)
{
  int Index = 0;
printf("Data processed at Receiver\n");  
  for(Index = 0; Index < INCOMING_STRAEM_SIZE; Index++)
  {
    printf("%f\n",ParameterData[Index]);
  }
  printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,MinValue,SMA);
}

void BMSReceiver( float *ParameterData, float* TemperatureData, float* SOCData, float* ChargeRateData)
{
  PrintReceiverDataOnConsole(TemperatureData,  MaxValue,  MinValue,  SMA)
}
