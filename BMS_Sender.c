#include "test_BMSData_Sender.h"
#include "BMS_Sender.h"


int SenderData(BatteryParameterInfo parameterInfo ,float (*funp_ReadDataFromSensor)(float,float)) {
  int index, inner_index;
  for(index=0; index<Sender.number_of_values; index++)
  {
    for(inner_index=0; inner_index<NoOfParameter; inner_index++)
    {
      parameterInfo[inner_index].parameterdata[index] = funp_ReadDataFromSensor(parameterInfo[inner_index].maximumThreshold, parameterInfo[inner_index].minimumThreshold);
    }
  }
  return 1;
}
