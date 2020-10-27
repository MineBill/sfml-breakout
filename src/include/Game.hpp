#pragma once
#include "GameData/GameData.hpp"
#include "GameInfo.hpp"
#include <SFML/Graphics.hpp>
#include <string>

// Main class responsible for the initialization, main loop
// and termination of the program
class Game {
  public:
    explicit Game(int argc, char **argv, const GameInfo& info = GameInfo());

    void Run();

  private:
    GameDataRef m_data;
    sf::RenderWindow m_window;
};
