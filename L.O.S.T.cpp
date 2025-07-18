#include <iostream>
#include <SFML/Graphics.hpp>
#include "Movement/Movement.hpp"
using namespace std;
using namespace sf;
Texture texture;

// Class player

class Player;

class Player
{
private:
	Sprite main_char;
	Vector2f position;
public:
	
	// Ham khoi tao nhan vat
	Player(Texture& texture)
		: main_char(texture) {
	};

	//------ Ham xu li di chuyen cua nhan vat ----\\
	
	void updatevitri_nv()
	{
		handleMovement(main_char);
	}
	
	void vemain_char(RenderWindow& window)
	{
		window.draw(main_char);
	}

};
int main()
{
	//-------------------------- KHOI TAO CAC HAM THANH PHAN (INITIALIZING)	---------------------------- \\
	
	RenderWindow game_win(VideoMode({ 1080,680 }), "L.O.S.T");

	// Viec lay kich co cua so phuc vu cho xu li viec cac sprite va map render theo solution cua user
	Vector2u origin_size = game_win.getSize();

	Vector2f map_size = Vector2f(1080.f, 680.f);


	View view(FloatRect({ 0.f,0.f }, { 1080.f,680.f }));
	game_win.setView(view);

	texture.loadFromFile("Asset/Nvat+animation/nv_test.png");
	
	// Khoi tao doi tuong player voi class Player

	Player main_char(texture);
	

	//-------------------------- KHOI TAO CAC HAM THANH PHAN (INITIALIZING)	---------------------------- \\
	
	//game loop
	while (game_win.isOpen())
	{						// --- NHAN THONG BAO TU NGUOI DUNG (INPUT)--- \\

		while (const optional event = game_win.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				game_win.close();
			}

			// Khi nguoi dung resize cua so
			if (event->getIf<sf::Event::Resized>())
			{
				Vector2u new_size = game_win.getSize();
				view.setCenter(Vector2f(new_size.x / 2.f, new_size.y / 2.f));
				view.setSize(Vector2f(new_size.x, new_size.y));
				origin_size = new_size;
			}
			// Luong xu li khi nguoi dung bam nut

			// Di chuyen:
			
			main_char.updatevitri_nv();

		}
		// --- NHAN THONG BAO TU NGUOI DUNG (INPUT)--- \\




//------------------------ UPDATE LOGIC GAME (SIMULATE)---------------- ------\\
		
		game_win.clear(Color::White);
		main_char.vemain_char(game_win);

		//-------- ------------------	-- UPDATE LOGIC GAME (SIMULATE)-------- ------\\
		

			//------------------------------XUAT RA WINDOW (RENDER) -----------------------------\\

		game_win.display();

	}
	return 0;
}