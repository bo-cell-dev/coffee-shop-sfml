#include "GameManager.h"
#include "UI.h"
#include "Menu.h"

void GameManager::init(TextureManager& tm) {
	customers.push_back(Customer(tm, "items", 155, 200, 400, 650, 5.f, 60.f));
	customers.push_back(Customer(tm, "money", 40, 280, 400, 550, 5.f, 160.f));

	tableMoneySprite = std::make_unique<sf::Sprite>(tm.createSprite("money", 0, 0, 200, 350, 80.f, 660.f));
	moneyClickZone = tableMoneySprite->getGlobalBounds();
}

void GameManager::handleMouseClick(sf::Vector2f mousePos, Menu& shopMenu, UI& ui) {
	if (isMoneyOnTable && moneyClickZone.contains(mousePos)) {
		isMoneyOnTable = false;
		addNumToScore();
		ui.updateScoreDisplay(score);
	}
	else {
		for (auto& item : shopMenu.getFoodItems()) {
			if (item.sprite.getGlobalBounds().contains(mousePos)) {
				isDragging = true;
				draggedItem = &item;
				originalPos = item.sprite.getPosition();
				break;
			}
		}
	}
}

void GameManager::handleMouseMove(sf::Vector2f mousePos) {
	if (isDragging && draggedItem != nullptr) {
		draggedItem->sprite.setPosition(mousePos);
	}
}
void GameManager::handleMouseRelease(TextureManager& tm, UI& ui) {
	if (isDragging && draggedItem != nullptr) {
		sf::Vector2f dropPos = draggedItem->sprite.getPosition();

		if (currentCustomerIndex < customers.size()) {
			auto& currentCustomer = customers[currentCustomerIndex];

			if (currentCustomer.getBounds().contains(dropPos)) {
				if (draggedItem->type == currentCustomer.getWant()) {
					isMoneyOnTable = true;
					currentCustomer.generateNewOrder(tm);

					if (currentCustomer.getIsLeft()) {
						currentCustomerIndex++;
						ui.clearOrder();

						if (currentCustomerIndex < customers.size()) {
							ui.setOrder(customers[currentCustomerIndex].getWant(), tm, { 5.f, 160.f });
						}
					}
					else {
						ui.setOrder(currentCustomer.getWant(), tm, { 5.f, 60.f });
					}
				}
			}
			draggedItem->sprite.setPosition(originalPos);
		}
		isDragging = false;
		draggedItem = nullptr;
	}
}


void GameManager::draw(sf::RenderWindow& window) {
	if (currentCustomerIndex < customers.size()) {
		customers[currentCustomerIndex].draw(window);
	}
	if (isMoneyOnTable && tableMoneySprite) {
		window.draw(*tableMoneySprite);
	}
}

void GameManager::setMenuItem(FoodItem item) {
	menu.push_back(std::move(item));
}

void GameManager::setCustomers(Customer customer) {
	customers.push_back(std::move(customer));
}

int GameManager::getCurrentCustomerIndex() const {
	return currentCustomerIndex;
}

void GameManager::setCurrentCustomerIndex(int index) {
	currentCustomerIndex = index;
}

void GameManager::setMoneyOnTable(bool var) {
	isMoneyOnTable = var;
}

bool GameManager::getMoneyOnTable() const {
	return isMoneyOnTable;
}

void GameManager::addNumToScore() {
	score += 25;
}

int GameManager::getScore() const {
	return score;
}

FoodItem* GameManager::getDraggedItem() {
	return draggedItem;
}

void GameManager::setDraggedItem(FoodItem* item) {
	draggedItem = item;
}

sf::Vector2f GameManager::getOriginalPos() const {
	return originalPos;
}

void GameManager::setOriginalPos(sf::Vector2f pos) {
	originalPos = pos;
}

bool GameManager::getIsDragging() const {
	return isDragging;
}

void GameManager::setIsDragging(bool var) {
	isDragging = var;
}

std::vector<Customer>& GameManager::getCustomers() {
	return customers;
}

std::vector<FoodItem>& GameManager::getMenu() {
	return menu;
}
