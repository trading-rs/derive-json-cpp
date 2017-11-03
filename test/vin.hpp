#pragma once

#include <derivejson/derivejson.hpp>

#include <json.hpp>
using json = nlohmann::json;

#include <string>
using namespace std;

namespace vin {
  DEFINE_MODEL(Vin, (string, transaction_id, "txid")(int, vout, "vout"))
  DEFINE_MODEL_JSON(VinJSON, (string, transaction_id, "txid")(int, vout, "vout"))
  DEFINE_MODEL_TO_JSON(VinToJSON, (string, transaction_id, "txid")(int, vout, "vout"))
  DEFINE_MODEL_FROM_JSON(VinFromJSON, (string, transaction_id, "txid")(int, vout, "vout"))
}

