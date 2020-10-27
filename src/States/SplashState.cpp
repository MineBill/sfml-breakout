#include "States/SplashState.hpp"
#include "States/MenuState.hpp"
#include <fmt/format.h>

SplashState::SplashState(GameDataRef t_data) : m_data(t_data) {
}

void SplashState::OnInit() {
    fmt::print("SplashState::OnInit\n");

    // LoadAsset should fail to find the texture named `awdnauwnd`
    // and instead should generate a default texture to indicate
    // a texture that is not found
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
