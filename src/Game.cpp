#include "Game.hpp"
#include "States/SplashState.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

Game::Game(int argc, char **argv, const GameInfo &info)
    : m_window(sf::VideoMode(info.dimensions.x, info.dimensions.y), info.name),
      m_data(std::make_shared<GameData>()) {
    m_data->state_machine.Init(std::make_unique<SplashState>(m_data));
}

void Game::Run() {
    sf::Clock loop_clock;
    while (m_window.isOpen()) {
        sf::Event event{};
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        auto time = loop_clock.restart();

        m_window.clear(sf::Color::Black);
        m_data->state_machine.Update(m_window,
                                     static_cast<double>(time.asSeconds()));
        m_window.display();
    }
}
