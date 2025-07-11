
#include "Movement.hpp"

void handleMovement(sf::Sprite& sprite, const std::optional<sf::Event>& event) {
	if (!event) return;

	const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
	if (keyPressed) {
		sf::Vector2f position = sprite.getPosition();

		switch (keyPressed->scancode) {
		case sf::Keyboard::Scancode::W:
			position.y -= 10.f; // Đi xuống
			break;
		case sf::Keyboard::Scancode::S:
			position.y += 10.f; // Đi lên
			break;
		case sf::Keyboard::Scancode::A:
			position.x -= 10.f; // Sang trái
			break;
		case sf::Keyboard::Scancode::D:
			position.x += 10.f; // Sang phải
			break;
		default:
			break;
		}

		sprite.setPosition(position);
	}
}
