#include "BanDan.hpp"

void shootbullet(Sprite& playerSprite, Texture& bulletTexture, std::vector<Sprite>& bullets) {
    Sprite bullet(bulletTexture);
    bullet.setPosition(playerSprite.getPosition());
    bullets.push_back(bullet);
}

void updateBullets(RenderWindow& window, std::vector<Sprite>& bullets, const Vector2u& windowSize) {
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        it->move(Vector2f(0.f, -10.f)); // Di chuyển viên đạn lên trên

        Vector2f pos = it->getPosition();
        if (pos.y < 0 || pos.y > windowSize.y || pos.x < 0 || pos.x > windowSize.x) {
            it = bullets.erase(it); // Xóa viên đạn nếu ra khỏi cửa sổ
        }
        else {
            window.draw(*it); // Vẽ viên đạn
            ++it;
        }
    }
}
