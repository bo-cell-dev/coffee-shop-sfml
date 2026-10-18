#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class TextureManager {
private:
	std::map<std::string, sf::Texture> m_textures;
public:
	void loadTexture(const std::string& name, const std::string& filename);
	const sf::Texture& getTexture(const std::string& name) const;
	sf::Sprite createSprite(const std::string& atlasName, int x, int y, int width, int height, float posX, float posY);
};