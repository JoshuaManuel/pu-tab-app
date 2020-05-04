#include "util/util.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

namespace util {
    std::string readFile (std::string path) {
        std::ifstream ifs;
        ifs = std::ifstream(path);

        if (!ifs.good()) {
            std::cout << "[FAILED TO LOAD FILE]" << std::endl;
            std::cout << path << std::endl;
            return "???";
        }
        std::stringstream buffer;
        buffer << ifs.rdbuf(); // allows us to use the .str method
        return buffer.str();
    }
}