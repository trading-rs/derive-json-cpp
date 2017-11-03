#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "vin.hpp"
using namespace vin;

#include <string>
using namespace std;

TEST_CASE("Auto generate JSON serializer and deserializer") {
  Vin vin_expected{"0x12312", 3};
  REQUIRE(vin_expected.transaction_id == "0x12312");
  REQUIRE(vin_expected.vout == 3);

  string json_str = "{\"txid\":\"0x12312\",\"vout\":3}";
  json j = json::parse(json_str);
  Vin vin_deserialize = j;
  REQUIRE(vin_deserialize == vin_expected);

  json j_serialize = vin_expected;
  REQUIRE(j_serialize.dump() == json_str);
}

TEST_CASE("Auto generate JSON serializer and deserializer without equal overload") {
  string json_str = "{\"txid\":\"0x12312\",\"vout\":3}";
  json j = json::parse(json_str);
  VinJSON vin_deserialize = j;

  json j_serialize = vin_deserialize;
  REQUIRE(j_serialize.dump() == json_str);
}

TEST_CASE("Auto generate JSON serializer") {
  VinToJSON vin_expected{"0x12312", 3};
  REQUIRE(vin_expected.transaction_id == "0x12312");
  REQUIRE(vin_expected.vout == 3);

  string json_str = "{\"txid\":\"0x12312\",\"vout\":3}";

  json j_serialize = vin_expected;
  REQUIRE(j_serialize.dump() == json_str);
}

TEST_CASE("Auto generate JSON deserializer") {
  VinFromJSON vin_expected{"0x12312", 3};
  REQUIRE(vin_expected.transaction_id == "0x12312");
  REQUIRE(vin_expected.vout == 3);

  string json_str = "{\"txid\":\"0x12312\",\"vout\":3}";
  json j = json::parse(json_str);
  VinFromJSON vin_deserialize = j;
  REQUIRE(vin_deserialize == vin_expected);
}
