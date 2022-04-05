#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "BMS_Sender.h"


float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  float data = (rand() % (int)(maximumThreshold - minimumThreshold +1)) + minimumThreshold ;
  return data;
}

float SimulateReadDataFromSensorInvalid(float minimumThreshold,float maximumThreshold)
{
  float data = NULL ;
  return data;
}

TEST_CASE("Test 1 : Prepare Data from Sensor : Valid Data") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 0.0;
  parameterInfo[0].maximumThreshold = 60.0;
  
  parameterInfo[1].minimumThreshold = 20.0;
  parameterInfo[1].maximumThreshold = 80.0;
  
  DataFromSender.number_of_values = 50;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor;
  
  srand(time(0));
  REQUIRE(SenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == TRUE);
}


TEST_CASE("Test 2 : Prepare Data from Sensor : Invalid Data") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 0.0;
  parameterInfo[0].maximumThreshold = 60.0;
  
  parameterInfo[1].minimumThreshold = 20.0;
  parameterInfo[1].maximumThreshold = 80.0;
  
  DataFromSender.number_of_values = 50;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensorInvalid;
  
  REQUIRE(SenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == FALSE);
}
