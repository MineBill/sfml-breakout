#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

struct GameInfo {
    sf::Vector2i dimensions{600, 400};
    std::string name{"Game"};
    bool fullscreen{false};

    GameInfo() = default;
    explicit GameInfo(const std::string& json_file);
};
