#include "Customer.h"

Customer::Customer(TextureManager& tm, const std::string& bodyAtlas, int bx, int by, int bw, int bh, float px, float py)
    : bodySprite(tm.createSprite(bodyAtlas, bx, by, bw, bh, px, py))
{
    basePos = { px, py };
    generateNewOrder(tm);
}

void Customer::generateNewOrder(TextureManager& tm) {
    ordersDone++;

    if (ordersDone > 2) {
        isLeft = true;
        return;
    }

    if (ordersDone == 1) {
        customerWant = "cake";
        m_currentOrder = Order("cake", 15);
    }
    else if (ordersDone == 2) {
        customerWant = "donut";
        m_currentOrder = Order("donut", 25);
    }
}

void Customer::draw(sf::RenderWindow& window) {
    if (!isLeft) {
        window.draw(bodySprite);
    }
}

std::string Customer::getWant() const {
    return customerWant;
}

sf::FloatRect Customer::getBounds() const {
    return bodySprite.getGlobalBounds();
}

bool Customer::getIsLeft() const {
    return isLeft;
}
