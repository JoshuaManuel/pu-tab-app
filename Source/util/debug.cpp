#include <iostream>
#include "util/debug.hpp"
#include "util/util.hpp"
#include "util/json.hpp"
#include "cfg/cfg.hpp"

using json = nlohmann::json;

namespace debug {
    void test() {
        cfg::loadStrings("en");
        std::cout << cfg::str(1);
        /*
        printf("printing to nxlink\n");
        //test json
        json j = "[\"student\", \"loans\"]"_json;

        auto cpp_string = j[1].get<std::string>();

        std::cout << cpp_string;
        std::cout << util::readFile("sdmc:/mGBA/config.ini");
        std::cout << util::readFile("romfs:/test.txt");
        */

    }
}