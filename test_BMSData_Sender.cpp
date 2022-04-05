#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "test_BMSData_Sender.h"
#include "BMS_Sender.h"

TEST_CASE("Test 1 : Prepare Data from Sensor") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  DataFromSender.number_of_values = 5;
  REQUIRE(SenderData(parameterInfo ,DataFromSender,funp_ReadDataFromSensor) == 1);
}
