#include "Game.h"
#include <iostream>

Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "ClickableGame", sf::State::Fullscreen),
	view(sf::FloatRect({ 0.f, 0.f }, { 768.f, 1024.f }))
{
	applyLetterbox(view, window.getSize());
	window.setView(view);

	try {
		textureManager.loadTexture("bg", "assets/BackGround.png");
		textureManager.loadTexture("items", "assets/CustomerFood.png");
		textureManager.loadTexture("money", "assets/CustomerMoney.png");
	}
	catch (const std::exception& e) {
		std::cerr << "Initialization failed: " << e.what() << std::endl;
	}

	background = std::make_unique<sf::Sprite>(textureManager.createSprite("bg", 0, 0, 768, 1024, 0.f, 0.f));
	gameManager = std::make_unique<GameManager>(); 

	ui.init(textureManager);
	menu.init(textureManager);
	gameManager->init(textureManager); 

	if (gameManager->getCurrentCustomerIndex() < gameManager->getCustomers().size()) {
		auto& firstCustomer = gameManager->getCustomers()[gameManager->getCurrentCustomerIndex()];
		ui.setOrder(firstCustomer.getWant(), textureManager, { 5.f, 60.f }); 
	}
}

void Game::applyLetterbox(sf::View& view, sf::Vector2u windowSize) {
	float targetRatio = 768.f / 1024.f;
	float windowRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);

	if (windowRatio > targetRatio) {
		float width = targetRatio / windowRatio;
		view.setViewport(sf::FloatRect({ (1.f - width) / 2.f, 0.f }, { width, 1.f }));
	}
	else {
		float height = windowRatio / targetRatio;
		view.setViewport(sf::FloatRect({ 0.f, (1.f - height) / 2.f }, { 1.f, height }));
	}
}

void Game::run() {
	while (window.isOpen()) {
		handleEvents();
		render();
	}
}

void Game::handleEvents() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}

		if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
			if (mouseClick->button == sf::Mouse::Button::Left) {
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				gameManager->handleMouseClick(mousePos, menu, ui);
			}
		}

		if (const auto* mouseMove = event->getIf<sf::Event::MouseMoved>()) {
			sf::Vector2f mousePos = window.mapPixelToCoords(mouseMove->position);
			gameManager->handleMouseMove(mousePos);
		}

		if (event->is<sf::Event::MouseButtonReleased>()) {
			gameManager->handleMouseRelease(textureManager, ui);
		}
	}
}

void Game::render() {
	window.clear();
	if (background) {
		window.draw(*background);
	}

	if (gameManager) {
		gameManager->draw(window);
	}
	menu.draw(window);
	ui.draw(window);

	window.display();
}
