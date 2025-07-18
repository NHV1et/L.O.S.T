/*
#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

void handleMovement(sf::Sprite& sprite, const std::optional<sf::Event>& event);

*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
// Hàm xử lý di chuyển sprite dựa trên trạng thái phím
void handleMovement(sf::Sprite& sprite);

//sf::Vector2f &map_size);
