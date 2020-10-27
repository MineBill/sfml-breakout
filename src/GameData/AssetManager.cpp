#include "GameData/AssetManager.hpp"

// Helper asset manager class hardcoded to only hold images (for now)
void AssetManager::LoadAsset(const std::string &name, const std::string &path) {
    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path)) {
        auto pixles = GenerateCheckerboard();
        texture->create(64, 64);
        texture->update(pixles);
    }
    m_assets[name] = texture;
}

TextureRef AssetManager::GetAsset(const std::string &name) {
    return m_assets[name];
}

sf::Uint8 *AssetManager::GenerateCheckerboard(int width, int height) {
    sf::Uint8 *pixels =
        new sf::Uint8[width * height * 4]; // 4: number of pixel components

    for (int x = 0; x < width * 4; x += 4) {
        for (int y = 0; y < height * 4; y += 4) {
            auto i = x * height + y;
            pixels[i + 0] = 255;
            pixels[i + 1] = 1;
            pixels[i + 2] = 1;
            pixels[i + 3] = 255;
        }
    }

    return pixels;
}
