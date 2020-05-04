#include "cfg/cfg.hpp"
#include "util/json.hpp"
#include "util/util.hpp"
#include <string>

using json = nlohmann::json;

namespace cfg {
    json strings;

    void loadStrings(std::string lang) {
        std::string s = util::readFile("romfs:/strings/" + lang + ".json");
        strings = json::parse(s);
    }

    std::string str(int num) {
        return strings[num].get<std::string>();
    }
}