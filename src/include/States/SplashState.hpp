#pragma once
#include "GameData/GameData.hpp"
#include "State.hpp"

class SplashState : public State {
  public:
    SplashState(GameDataRef t_data);

    virtual void OnInit() override;
    virtual void OnUpdate(sf::RenderTarget &target, double t_delta) override;

  private:
    GameDataRef m_data{};
    double m_counter{0.0};

    const double SPLASH_TIME{6.0};
};
