#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Receiver.h"

SCENARIO("Scene1: As part of receiver, read the data sent by sender")
{
    GIVEN(" Sender data is on console")
    {
        WHEN(" Format of console and receiver are same")
        {
            int NuberOfValues = 3;
            float TemperatureData[NuberOfValues] = {0};
            float SOCData[NuberOfValues] = {0};
            float ChargeRateData [NuberOfValues] = {0};

            THEN("Check whether data is read from console successfully")
            {
                REQUIRE(ReceiveDataFromConsole(TemperatureData,SOCData,ChargeRateData) == E_OK);
            }
        }
    }
}
SCENARIO("Scene2: As part of receiver, read the data and process to get the statistics")
{
    GIVEN(" Receiver data in CSV format")
     {
        int NuberOfValues = 10; //INCOMING_STREAM_SIZE

        float ParameterData[NuberOfValues] = {5,2,6,4,3,1,1,2,3,4};

        THEN("Check whether data is to find min and max values")
        {
            REQUIRE(GetMaxValueOfIncomingStream(ParameterData) == 6.0f);
            REQUIRE(GetMinValueofIncomingStream(ParameterData) == 1.0f);
            REQUIRE(GetSMAofIncomingStream(ParameterData, 5) == 2.2f);
        }
    }
}

SCENARIO("Scene3: As part of receiver, read the data and process to get the statistics and Print on console")
{
    GIVEN(" Receiver data in CSV format")
     {
        int NuberOfValues = 10; //INCOMING_STREAM_SIZE

        float Temperature[NuberOfValues] = {5,2,6,4,3,1,1,2,3,4};
        float SOC[NuberOfValues] = {5,2,6,4,3,1,1,2,3,4};
        float ChargeRate[NuberOfValues] = {5,2,6,4,3,1,1,2,3,4};

        THEN("Check whether data is to find min and max values")
        {
            REQUIRE(GetMaxValueOfIncomingStream(Temperature) == 6.0f);
            REQUIRE(GetMinValueofIncomingStream(SOC) == 1.0f);
            REQUIRE(GetSMAofIncomingStream(ChargeRate, 5) == 2.2f);
            
            BMSReceiver(  Temperature,  SOC,  ChargeRate);
        }
    }
}
