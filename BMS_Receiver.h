#pragma once

#define Number_of_values 50 //DataFromSender->number_of_values

typedef struct {
  float parameterdata[50];
} ReceiverBatteryParameterInfo;

void ReceiveDataFromConsole(ReceiverBatteryParameterInfo *parameterInfo);
void BMSReceiver(ReceiverBatteryParameterInfo *parameterInfo);
