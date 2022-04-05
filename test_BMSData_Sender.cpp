#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Sender.h"

TEST_CASE("Test 1 : Prepare Data from Sensor") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender SenderData ;
  REQUIRE(SenderData(BatteryParameterInfo parameterInfo ,Sender SenderData, float (*funp_ReadDataFromSensor)(float,float)) == 1);
}
