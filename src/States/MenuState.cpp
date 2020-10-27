#include "States/MenuState.hpp"
#include <fmt/format.h>

MenuState::MenuState(GameDataRef _data) : m_data(_data) {
}

void MenuState::OnInit() {
    fmt::print("MenuState::OnInit\n");
}
