#include "GameData/GameData.hpp"
#include "States/SplashState.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    GameDataRef m_data = std::make_shared<GameData>();
    m_data->state_machine.Init(std::make_unique<SplashState>(m_data));

    sf::Clock loop_clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        auto time = loop_clock.restart();

        window.clear(sf::Color::Black);
        m_data->state_machine.Update(window,
                                     static_cast<double>(time.asSeconds()));
        window.display();
    }

    return 0;
}
