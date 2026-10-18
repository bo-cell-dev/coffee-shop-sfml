#include "UI.h"
#include <iostream>

void UI::init(TextureManager& textureManager) {
	if (!font.openFromFile("assets/TildaSans-VF.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
		return;
	}

	scoreText = std::make_unique<sf::Text>(font);
	scoreText->setCharacterSize(40);
	scoreText->setFillColor(sf::Color::White);
	scoreText->setStyle(sf::Text::Bold);
	scoreText->setPosition({ 160.f, 50.f });
	scoreText->setString("0");

	frameSprite = std::make_unique<sf::Sprite>(textureManager.createSprite("money", 250, 0, 500, 300, 250.f, 10.f));
	orderVisual = nullptr; 
}

void UI::updateScoreDisplay(int currentScore) {
	if (!scoreText) return;

	if (currentScore >= 100) {
		scoreText->setString("Win");
	}
	else {
		scoreText->setString(std::to_string(currentScore));
	}
}

void UI::setOrder(const std::string& type, TextureManager& tm, sf::Vector2f basePos) {
	if (type == "cake") {
		orderVisual = std::make_unique<sf::Sprite>(tm.createSprite("items", 190, 0, 200, 192, 500.f, 100.f));
	}
	else if (type == "donut") {
		orderVisual = std::make_unique<sf::Sprite>(tm.createSprite("items", 560, 0, 200, 192, 500.f, 100.f));
	}
}

void UI::clearOrder() {
	orderVisual = nullptr;
}

void UI::draw(sf::RenderWindow& window) {
	if (scoreText) window.draw(*scoreText);
	if (frameSprite) window.draw(*frameSprite);
	if (orderVisual) window.draw(*orderVisual); 
}
