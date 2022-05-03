#pragma once

#define Number_of_values 50 //DataFromSender->number_of_values

typedef struct {
  float parameterdata[50];
} ReceiverBatteryParameterInfo;

typedef enum
{
	E_NOT_OK,
	E_OK
}StatusType;

StatusType ReceiveDataFromConsole(ReceiverBatteryParameterInfo *parameterInfo);
void BMSReceiver(ReceiverBatteryParameterInfo *parameterInfo);
