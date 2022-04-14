#include <stdio.h>
#include "BMS_Receiver.h"
#include "BMS_Sender.h"

void ReceiveDataFromConsole(ReceiverBatteryParameterInfo  *parameterInfo)
{
 
  int index;
  int inner_index;
  for(index=0;index<Number_of_values;index++)
  {
    for(inner_index=0; inner_index<NoOfParameter-1; inner_index++)
    {
       scanf("%f ,",parameterInfo[index].parameterdata[inner_index]);
    }
    scanf("%f \n",parameterInfo[index].parameterdata[inner_index]);
  }
}

void BMSReceiver(ReceiverBatteryParameterInfo  *parameterInfo)
{

  ReceiveDataFromConsole(&parameterInfo);
}
