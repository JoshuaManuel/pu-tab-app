#pragma once

#include <string>
#include "util/json.hpp"

using json = nlohmann::json;

namespace cfg {
    void loadStrings(std::string lang);
    std::string str(int num);
}