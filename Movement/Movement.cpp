
#include "Movement.hpp"

void handleMovement(sf::Sprite& sprite) 
	//,sf::Vector2f &map_size) 
	{
	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
		sprite.setPosition(position + sf::Vector2f(0,-10));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
		sprite.setPosition(position + sf::Vector2f(0, 10));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
		sprite.setPosition(position + sf::Vector2f(-10, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
		sprite.setPosition(position + sf::Vector2f(10, 0));
	}

	
}
