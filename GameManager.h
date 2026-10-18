#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Customer.h"
#include "FoodItem.h"

class Menu;
class UI;

class GameManager {
private:
	int score = 0;
	std::vector<FoodItem> menu;
	bool isDragging = false;
	FoodItem* draggedItem = nullptr;
	sf::Vector2f originalPos;
	std::vector<Customer> customers;
	int currentCustomerIndex = 0;
	bool isMoneyOnTable = false;
	std::unique_ptr<sf::Sprite> tableMoneySprite;
	sf::FloatRect moneyClickZone;

public:
	GameManager() = default;
	void init(TextureManager& tm);
	void handleMouseClick(sf::Vector2f mousePos, Menu& shopMenu, UI& ui);
	void handleMouseMove(sf::Vector2f mousePos);
	void handleMouseRelease(TextureManager& tm, UI& ui);
	void draw(sf::RenderWindow& window);

	void setMenuItem(FoodItem item);
	void setCustomers(Customer customer);

	int getCurrentCustomerIndex() const;
	void setCurrentCustomerIndex(int index);

	void setMoneyOnTable(bool var);
	bool getMoneyOnTable() const;

	void addNumToScore();
	int getScore() const;

	FoodItem* getDraggedItem();
	void setDraggedItem(FoodItem* item);

	sf::Vector2f getOriginalPos() const;
	void setOriginalPos(sf::Vector2f pos);

	bool getIsDragging() const;
	void setIsDragging(bool var);

	std::vector<Customer>& getCustomers();
	std::vector<FoodItem>& getMenu();
};
