#pragma once
#include "GameData/GameData.hpp"
#include "State.hpp"

class MenuState : public State {
  public:
    MenuState(GameDataRef t_data);
    virtual void OnInit() override;

  private:
    GameDataRef m_data;
};
