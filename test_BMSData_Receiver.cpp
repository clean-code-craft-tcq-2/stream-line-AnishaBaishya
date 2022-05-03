#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Receiver.h"

SCENARIO("As part of receiver, read the data sent by sender")
{
    GIVEN(" Sender data is on console")
    {
        WHEN(" Format of console and receiver are same")
        {
            int NuberOfValues = 3;
            ReceiverBatteryParameterInfo ReceiverParameterInfo [NuberOfValues] = {0};

            THEN("Check whether data is read from console successfully")
            {
                REQUIRE(ReceiveDataFromConsole(ReceiverParameterInfo) == E_OK);
            }
        }
    }
}
SCENARIO("As part of receiver, read the data and process to get the statistics")
{
    GIVEN(" Receiver data in CSV format")
     {
        int NuberOfValues = 6;
        ReceiverBatteryParameterInfo ReceiverParameterInfo [NuberOfValues] = {0};//
        float ParameterInfo[NuberOfValues] = {5,2,6,4,3,1};

        THEN("Check whether data is to find min and max values")
        {
            REQUIRE(ReceiveDataFromConsole(ReceiverParameterInfo) == E_OK);//
            REQUIRE(GetMaxValueOfIncomingStream(ParameterInfo) == 6);
        }
    }
}
