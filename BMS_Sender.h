
typedef enum {
  TempParameter,
  SOCParameter,
  NoOfParameter
} EV_BatteryParameterTypesForBMS;


typedef struct {
  EV_BatteryParameterTypesForBMS parameter;
  float parameterdata[50];
} BatteryParameterInfo;

typedef struct  {
  int number_of_values;
  char formatted_senderdata[50];
} Sender;

