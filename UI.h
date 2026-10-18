#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class UI {
private:
	sf::Font font;
	std::unique_ptr<sf::Text> scoreText;
	std::unique_ptr<sf::Sprite> frameSprite;
	std::unique_ptr<sf::Sprite> orderVisual; 
public:
	UI() = default;
	void init(TextureManager& textureManager);
	void updateScoreDisplay(int currentScore);
	void setOrder(const std::string& type, TextureManager& tm, sf::Vector2f basePos); 
	void clearOrder(); 
	void draw(sf::RenderWindow& window);
};
