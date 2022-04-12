#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "BMS_Sender.h"


float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  float data = (rand() % (int)(maximumThreshold+1)) ;
  if(data < minimumThreshold)
  {
    data = data + minimumThreshold;
  }
  return data;
}

float SimulateReadDataFromSensorInvalid(float minimumThreshold,float maximumThreshold)
{
  float data = NULL ;
  return data;
}

float SimulateReadDataFromSensor_ManualData(float minimumThreshold,float maximumThreshold)
{
  float Data;
  if(minimumThreshold == 5.0)
    Data = 10.0;
  if(minimumThreshold == 10.0)
    Data = 35.0;
  return Data;
}
  
TEST_CASE("Test 1 : Prepare Data from Sensor : Valid Data") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 0.0;
  parameterInfo[0].maximumThreshold = 70.0;
  
  parameterInfo[1].minimumThreshold = 10.0;
  parameterInfo[1].maximumThreshold = 80.0;
  
  DataFromSender.number_of_values = 50;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor;
  
  srand(time(0));
  REQUIRE(ProcessSenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == TRUE);
}


TEST_CASE("Test 2 : Prepare Data from Sensor : Invalid Data") {

  BatteryParameterInfo parameterInfo1 [NoOfParameter] ;
  Sender DataFromSender1 ;
  
  parameterInfo1[0].minimumThreshold = 0.0;
  parameterInfo1[0].maximumThreshold = 40.0;
  
  parameterInfo1[1].minimumThreshold = 20.0;
  parameterInfo1[1].maximumThreshold = 80.0;
  
  DataFromSender1.number_of_values = 5;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensorInvalid;
  
  REQUIRE(ProcessSenderData(parameterInfo1 ,&DataFromSender1,funp_ReadDataFromSensor) == FALSE);
}

TEST_CASE("Test 3 : Prepare Data from Sensor : Manual Data") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 5.0;
  parameterInfo[0].maximumThreshold = 20.0;
  
  parameterInfo[1].minimumThreshold = 10.0;
  parameterInfo[1].maximumThreshold = 50.0;
  
  DataFromSender.number_of_values = 2;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor_ManualData;
  
  REQUIRE(ProcessSenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == TRUE);
}
