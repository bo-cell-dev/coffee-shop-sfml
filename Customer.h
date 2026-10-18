#pragma once
#include "Order.h"
#include "TextureManager.h"
#include <string>

class Customer {
private:
    sf::Sprite bodySprite;
    std::string customerWant;
    int ordersDone = 0;
    bool isLeft = false;
    sf::Vector2f basePos;
    Order m_currentOrder;

public:
    Customer(TextureManager& tm, const std::string& bodyAtlas, int bx, int by, int bw, int bh, float px, float py);
    void generateNewOrder(TextureManager& tm);
    void draw(sf::RenderWindow& window);
    std::string getWant() const;
    sf::FloatRect getBounds() const;
    bool getIsLeft() const;
};
