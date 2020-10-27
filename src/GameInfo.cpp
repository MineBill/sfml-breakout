#include "GameInfo.hpp"
#include <fmt/format.h>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Load json file containing game info
GameInfo::GameInfo(const std::string &json_file) {
    std::ifstream file(json_file);

    if (file.is_open()) {
        json j;
        file >> j;
        if (j.contains("dimensions")) {
            json d = j["dimensions"];
            if (d.contains("x") && d.contains("y")) {
                int x = d["x"];
                int y = d["y"];

                dimensions = sf::Vector2i(x, y);
            } else {
                fmt::print(
                    "WARNING: Missing `x` or `y` members from `dimension`\n");
            }
        } else {
            fmt::print("WARNING: Missing `dimensions`\n");
        }

        if (j.contains("fullscreen")) {
            fullscreen = j["fullscreen"];
        }else {
            fmt::print("WARNING: Missing `fullscreen`\n");
        }

        if (j.contains("name")) {
            name = j["name"];
        }else {
            fmt::print("WARNING: Missing `name`\n");
        }
    }
}

