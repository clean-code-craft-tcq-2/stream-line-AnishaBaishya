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
            ReceiverBatteryParameterInfo ReceiverParameterInfo [NuberOfValues];

            THEN("Check weather data is read from console successfully")
            {
               
                REQUIRE(ReceiveDataFromConsole(ReceiverParameterInfo) == E_OK)
            }
        }
    }
}
