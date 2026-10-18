#pragma once
#include <string>

class Order {
private:
    int cost = 15;
    std::string foodType;

public:
    Order() = default;
    Order(std::string type, int price) : foodType(type), cost(price) {}

    int getCost() const { return cost; }
    std::string getFoodType() const { return foodType; }
};
