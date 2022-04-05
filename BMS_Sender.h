
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
} BatteryParameterInfo;

typedef struct  {
  int number_of_values;
  char formatted_senderdata[50];
} Sender;



int SenderData(BatteryParameterInfo parameterInfo ,Sender DataFromSender, float (*funp_ReadDataFromSensor)(float,float));
