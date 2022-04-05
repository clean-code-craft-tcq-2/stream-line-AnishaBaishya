#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Sender.h"

TEST_CASE("Test 1 : Prepare Data from Sensor") {

  REQUIRE(SenderData() == 1);
}
