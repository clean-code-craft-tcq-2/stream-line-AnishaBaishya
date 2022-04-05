#include <string>

int SenderData();



typedef enum {
  TempParameter,
  SOCParameter,
  ChargeRateParameter,
  NoOfParameter
} EV_BatteryParameterTypesForBMS;


typedef struct {
  EV_BatteryParameterTypesForBMS parameter;
  float minimumThreshold;
  float maximumThreshold;
  float parameterdata[50];
  char parameterName[100];
} BatteryParameterInfo;

typedef struct  {
  int number_of_values;
  string formatted_senderdata[50];
} Sender;
