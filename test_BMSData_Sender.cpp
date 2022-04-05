#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "test_BMSData_Sender.h"
#include "BMS_Sender.h"

TEST_CASE("Test 1 : Prepare Data from Sensor") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  parameterInfo[0].minimumThreshold = 0;
  parameterInfo[0].maximumThreshold = 45.0;
    
  parameterInfo[1].minimumThreshold = 20;
  parameterInfo[1].maximumThreshold = 80;

  parameterInfo[2].minimumThreshold = 0;
  parameterInfo[2].maximumThreshold = 0.8;
  Sender DataFromSender ;
  DataFromSender.number_of_values = 5;
  REQUIRE(SenderData(parameterInfo ,DataFromSender,funp_ReadDataFromSensor) == 1);
}
