#include "States/SplashState.hpp"
#include "States/MenuState.hpp"
#include <fmt/format.h>

SplashState::SplashState(GameDataRef t_data) : m_data(t_data) {
}

void SplashState::OnInit() {
    fmt::print("SplashState::OnInit\n");
    m_data->assets.LoadAsset("foo", "awdnauwnd");

    auto texture = m_data->assets.GetAsset("foo").get();
    m_sprite.setTexture(*texture);
}

void SplashState::OnUpdate(sf::RenderTarget &target, double t_delta) {
    m_counter += t_delta;

    if (m_counter >= SPLASH_TIME) {
        m_data->state_machine.Push(std::make_unique<MenuState>(m_data));
    }

    target.draw(m_sprite);
}
