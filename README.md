# Automatically generate JSON serializers and deserializers

[![Build Status](https://travis-ci.org/zjhmale/derive-json-cpp.svg?branch=master)](https://travis-ci.org/zjhmale/derive-json-cpp)

## Getting Started

### Prerequisite

```sh
git submodule update --init --recursive
```

### Build and Test

```sh
./build.sh
```

### Examples

```C++
#include <derivejson/derivejson.hpp>

#include <json.hpp>
using json = nlohmann::json;

#include <iostream>
#include <string>
using namespace std;

namespace vin {
  DEFINE_MODEL(Vin, (string, transaction_id, "txid")(int, vout, "vout")) 
}

int main(int argc, char** argv) {
  using namespace vin;

  json j = json::parse("{\"txid\":\"0x12312\",\"vout\":3}");
  Vin vin_deserialize = j;

  cout << vin_deserialize.transaction_id << endl;
  cout << vin_deserialize.vout << endl;

  json j_serialize = vin_deserialize;
  cout << j_serialize.dump() << endl;
}
```

