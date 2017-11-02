#pragma once

#include <derivejson/derivejson.hpp>

#include <json.hpp>
using json = nlohmann::json;

#include <string>
using namespace std;

namespace vin {
  DEFINE_MODEL(Vin, (string, transaction_id, "txid")(int, vout, "vout")) 
}

