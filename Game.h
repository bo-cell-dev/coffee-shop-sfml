#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Menu.h"
#include "UI.h"

class Game {
private:
	sf::RenderWindow window;
	sf::View view;
	TextureManager textureManager;
	std::unique_ptr<sf::Sprite> background;
	Menu menu;
	std::unique_ptr<GameManager> gameManager; 
	UI ui;

public:
	Game();
	void applyLetterbox(sf::View& view, sf::Vector2u windowSize);
	void run();
	void handleEvents();
	void render();
};
