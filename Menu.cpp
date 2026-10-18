#include "Menu.h"

void Menu::init(TextureManager& textureManager) {
	foodItems.push_back(FoodItem(textureManager.createSprite("items", 0, 32, 200, 192, 70.f, 920.f), "apple"));
	foodItems.push_back(FoodItem(textureManager.createSprite("items", 190, 0, 200, 192, 210.f, 890.f), "cake"));
	foodItems.push_back(FoodItem(textureManager.createSprite("items", 368, 0, 220, 192, 330.f, 890.f), "lollipop"));
	foodItems.push_back(FoodItem(textureManager.createSprite("items", 560, 0, 200, 192, 470.f, 890.f), "donut"));
}

FoodItem* Menu::checkClick(sf::Vector2f mousePos) {
	for (auto& item : foodItems) {
		if (item.sprite.getGlobalBounds().contains(mousePos)) {
			return &item;
		}
	}
	return nullptr;
}

void Menu::draw(sf::RenderWindow& window) {
	for (const auto& item : foodItems) {
		window.draw(item.sprite);
	}
}

std::vector<FoodItem>& Menu::getFoodItems() {
	return foodItems;
}
