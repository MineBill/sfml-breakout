#pragma once
#include "AssetManager.hpp"
#include "StateMachine.hpp"

struct GameData {
    StateMachine state_machine;
    AssetManager assets;
};
using GameDataRef = std::shared_ptr<GameData>;
