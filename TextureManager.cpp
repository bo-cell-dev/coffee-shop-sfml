#include "TextureManager.h"

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    if (m_textures.find(name) != m_textures.end()) {
        return;
    }
    sf::Texture tex;
    if (!tex.loadFromFile(filename)) {
        throw std::exception();
    }
    m_textures[name] = std::move(tex);
}
const sf::Texture& TextureManager::getTexture(const std::string& name) const {
    auto it = m_textures.find(name);
    if (it != m_textures.end()) {
        return it->second;
    }
    throw std::exception();
}
sf::Sprite TextureManager::createSprite(const std::string& atlasName, int x, int y, int width, int height, float posX, float posY) {
    const sf::Texture& tex = getTexture(atlasName);

    sf::Sprite sprite(tex);
    sprite.setTextureRect(sf::IntRect({ x, y }, { width, height }));
    sprite.setPosition({ posX, posY });

    return sprite;
}