#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Receiver.h"
#include "BMS_Sender.h"

SCENARIO("As part of receiver, read the data sent by sender")
{
    GIVEN(" Sender data is on console")
    {
        WHEN(" Format of console and receiver are same")
        {
            int NumberOfParameters = 2;
            int NuberOfValues = 3;
            BatteryParameterInfo ReceiverParameterInfo [NuberOfValues] = {0};
            BatteryParameterInfo parameterInfo [NuberOfValues] = {0};
            parameterInfo.parameterdata[NumberOfParameters] ={/*parameter1*/{22, 23, 24},
                                                              /*parameter2*/{32, 33, 34}};

            THEN("Check weather data is read from console successfully")
            {
              Sender DataFromSender ; DataFromSender.number_of_values = 2;
               DisplaySensorDataOnConsole(parameterInfo ,DataFromSender);
              
               ReceiveDataFromConsole(&ReceiverParameterInfo);
                  for(index=0;index<DataFromSender->NuberOfValues;index++)
                  {
                    for(inner_index=0; inner_index<NumberOfParameters-1; inner_index++)
                    {
                      REQUIRE(parameterInfo[inner_index].parameterdata[index]==ReceiverParameterInfo[inner_index].ReceiverParameterInfo[index]);
                    }
                    REQUIRE(parameterInfo[NumberOfParameters-1].parameterdata[index]==ReceiverParameterInfo[NumberOfParameters-1].ReceiverParameterInfo[index]);
                  }
            }
        }
    }
}
