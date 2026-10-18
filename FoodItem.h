#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class FoodItem {
public:
    sf::Sprite sprite;
    std::string type; 

    FoodItem(sf::Sprite s, std::string t) : sprite(s), type(t) {}
};