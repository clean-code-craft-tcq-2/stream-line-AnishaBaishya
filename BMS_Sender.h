#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE  0
#define FALSE 1

typedef enum {
  TempParameter,
  SOCParameter,
  NoOfParameter
} EV_BatteryParameterTypesForBMS;


typedef struct {
  EV_BatteryParameterTypesForBMS parameter;
  float minimumThreshold;
  float maximumThreshold;
  float parameterdata[50];
} BatteryParameterInfo;

typedef struct  {
  int number_of_values;
  char formatted_senderdata[50];
} Sender;


bool ProcessSenderData(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender, float (*funp_ReadDataFromSensor)(float,float));
void DisplaySensorDataOnConsole(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender);
