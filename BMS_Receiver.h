#pragma once

#define INCOMING_STRAEM_SIZE 10 //DataFromSender->number_of_values

typedef enum
{
	E_NOT_OK,
	E_OK
}StatusType;

StatusType ReceiveDataFromConsole(float  *TemperatureData, float *SOCData, float *ChargeRateData);
void BMSReceiver(float *ParameterData);

float GetMaxValueOfIncomingStream(float *ParameterData);
float GetMinValueofIncomingStream(float *ParameterData);
float GetSMAofIncomingStream(float *ParameterData, int WindowSize);
