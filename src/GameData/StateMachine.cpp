#include "GameData/StateMachine.hpp"

void StateMachine::Init(StateRef t_state) {
    m_states.push(std::move(t_state));
    m_states.top()->OnInit();
}

// Called every frame
void StateMachine::Update(sf::RenderTarget &target, double t_delta) const {
    m_states.top()->OnUpdate(target, t_delta);
}

// Push new state into the stack
void StateMachine::Push(StateRef t_state) {
    if (m_states.size() > 0) {
        auto &old = m_states.top();
        old->Pause();
    }
    m_states.push(std::move(t_state));
    m_states.top()->OnInit();
}

// Pop the top state of the stack
void StateMachine::Pop() {
    auto &state = m_states.top();
    state->OnPop();
    m_states.pop();
    m_states.top()->Resume();
}
