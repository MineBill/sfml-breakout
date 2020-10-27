#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

class State {
  public:
    virtual ~State() {
    }
    // Initialize
    virtual void OnInit() = 0;
    // Called every frame
    virtual void OnUpdate(sf::RenderTarget &target, double t_delta){};
    // Called every frame
    virtual void OnDraw(){};
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
