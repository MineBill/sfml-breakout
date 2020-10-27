#pragma once
#include "State.hpp"
#include <stack>

class StateMachine {
  public:
    // Initialize
    void Init(StateRef t_state);
    // Called every frame
    void Update(sf::RenderTarget &target, double t_delta) const;

    // Push new state into the stack
    void Push(StateRef t_state);
    // Pop the top state of the stack
    void Pop();

  private:
    std::stack<StateRef> m_states;
};
