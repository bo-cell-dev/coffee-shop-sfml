#pragma once
#include <vector>
#include "FoodItem.h"
#include "TextureManager.h"

class Menu {
private:
	std::vector<FoodItem> foodItems;
public:
	void init(TextureManager& textureManager);
	FoodItem* checkClick(sf::Vector2f mousePos);
	void draw(sf::RenderWindow& window);
	std::vector<FoodItem>& getFoodItems();
};
