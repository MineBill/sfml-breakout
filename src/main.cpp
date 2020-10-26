#include <SFML/Graphics.hpp>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

class State {
  public:
    // Initialize
    virtual void OnInit(){};
    // Called every frame
    virtual void OnUpdate(double t_delta){};
    // Called when this state is popped from the stack
    virtual void OnPop(){};

    // Called when a new state is pushed on the stack
    // and execution of this state is paused
    virtual void Pause(){};
    // Called when the top state is popped from the stack
    // and execution is resumed to this state
    virtual void Resume(){};
};

using StateRef = std::unique_ptr<State>;

class StateMachine {
  public:
    // Initialize
    void Init(StateRef t_state) {
        m_states.push(std::move(t_state));
        m_states.top()->OnInit();
    }

    // Called every frame
    void Update(double t_delta) const {
        m_states.top()->OnUpdate(t_delta);
    }

    // Push new state into the stack
    void Push(StateRef t_state) {
        if (m_states.size() > 0) {
            auto &old = m_states.top();
            old->Pause();
        }
        m_states.push(std::move(t_state));
        m_states.top()->OnInit();
    }

    // Pop the top state of the stack
    void Pop() {
        auto &state = m_states.top();
        state->OnPop();
        m_states.pop();
        m_states.top()->Resume();
    }

  private:
    std::stack<StateRef> m_states;
};

// Holds basic data that need to be accessed by states to perform basic
// operations
struct GameData {
    StateMachine state_machine;
};
using GameDataRef = std::shared_ptr<GameData>;

// State that shows a basic menu(not yet)
class MenuState : public State {
  public:
    MenuState(GameDataRef t_data) : m_data(t_data) {
    }

    virtual void OnInit() {
        fmt::print("MenuState initialzed\n");
    }

  private:
    GameDataRef m_data;
};

// State that shows a splash image during the start
class SplashState : public State {
  public:
    SplashState(GameDataRef t_data) : m_data(t_data) {
    }

    virtual void OnInit() override {
        fmt::print("SplashState initialzed\n");
    }

    virtual void OnUpdate(double t_delta) override {
        m_counter += t_delta;

        if (m_counter >= SPLASH_TIME) {
            m_data->state_machine.Push(std::make_unique<MenuState>(m_data));
        }
    }

  private:
    GameDataRef m_data{};
    double m_counter{0.0};

    const double SPLASH_TIME{6.0};
};

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
        m_data->state_machine.Update(static_cast<double>(time.asSeconds()));

        // ### Drawing ###
        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}
