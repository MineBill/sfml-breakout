#pragma once
#include "StateMachine.hpp"

struct GameData {
    StateMachine state_machine;
};
using GameDataRef = std::shared_ptr<GameData>;
