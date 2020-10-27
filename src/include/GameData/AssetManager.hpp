#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>
#include <ranges>

using TextureRef = std::shared_ptr<sf::Texture>;

// Helper asset manager class hardcoded to only hold images (for now)
class AssetManager {
  public:
    void LoadAsset(const std::string &name, const std::string &path);

    TextureRef GetAsset(const std::string &name);

  private:
    sf::Uint8 *GenerateCheckerboard(int width = 64, int height = 64);

  private:
    std::map<std::string, TextureRef> m_assets;
};
