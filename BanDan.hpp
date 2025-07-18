#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

// Hàm tạo viên đạn từ vị trí của player
void shootbullet(Sprite& playerSprite, Texture& bulletTexture, std::vector<Sprite>& bullets);

// Hàm cập nhật và vẽ viên đạn, xóa nếu ra khỏi cửa sổ
void updateBullets(RenderWindow& window, std::vector<Sprite>& bullets, const Vector2u& windowSize);
