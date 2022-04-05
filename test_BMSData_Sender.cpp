#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"

TEST_CASE("Test 1 : Prepare Data from Sensor") {

  REQUIRE(SenderData() == 1);
}
