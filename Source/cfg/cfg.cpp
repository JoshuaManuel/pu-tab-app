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

    std::string str(int num) { //use actual line number of language file (this function subtracts 2 from the given number)
        if (num-2 >= strings.size()) {
            return "???";
        }
        return strings[num-2].get<std::string>();
    }
}