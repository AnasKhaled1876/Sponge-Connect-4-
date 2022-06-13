//#include"pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include <iostream>
using namespace std;
char place[8][8];
int drop(int b, char player, sf::Sprite&, sf::Sprite&);
bool check(int a, int b);
int main()
{
	int count = 0;
	int row = 0;
	int col = -1;
	int spongies = 0;//Number of peices dropped so can end game if a draw
	char player = 15;
	bool playb = true;
	bool gamewon = false;
	bool exitb = true;
	bool fool = true;
	bool optionb = true;
	bool _spongpop3 = true;
	bool _Squidward3 = true;
	bool _Patrick3 = true;
	bool _MrKrabs3 = true;
	bool _Plankton3 = true;
	bool _Sandy3 = true;
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Connect 4");
	// Create a texture

	//1 spongpop

	sf::Texture spongpop;
	// Load image file into that texture
	spongpop.loadFromFile("spongpop.PNG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite> _spongpop(64, sf::Sprite(spongpop));
	for (int i = 0; i < 64; i++)
		_spongpop[i].setPosition(sf::Vector2f(107.5, 7.5));

	//2 patrick

	sf::Texture patrick;
	// Load image file into that texture
	patrick.loadFromFile("Patrick.PNG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite> _patrick(64, sf::Sprite(patrick));
	for (int i = 0; i < 64; i++)
		_patrick[i].setPosition(sf::Vector2f(107.5, 7.5));


	//3 Plankton
	sf::Texture Plankton;
	// Load image file into that texture
	Plankton.loadFromFile("Plankton.JPG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite> _Plankton(32, sf::Sprite(Plankton));
	for (int i = 0; i < 32; i++)
		_Plankton[i].setPosition(sf::Vector2f(107.5, 7.5));

	/// 4 Squidward
	sf::Texture Squidward;
	// Load image file into that texture
	Squidward.loadFromFile("Squidward.JPG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite>_Squidward(32, sf::Sprite(Squidward));
	for (int i = 0; i < 32; i++)
		_Squidward[i].setPosition(sf::Vector2f(107.5, 7.5));


	//5 Sandy
	sf::Texture Sandy;
	// Load image file into that texture
	Sandy.loadFromFile("Sandy.JPG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite> _Sandy(32, sf::Sprite(Sandy));
	for (int i = 0; i < 32; i++)
		_Sandy[i].setPosition(sf::Vector2f(107.5, 7.5));

	//6 MrKrabs
	sf::Texture MrKrabs;
	// Load image file into that texture
	MrKrabs.loadFromFile("MrKrabs.JPG");
	// Create a vector of 10 sprites initialised with the texture above
	std::vector<sf::Sprite> _MrKrabs(32, sf::Sprite(MrKrabs));
	for (int i = 0; i < 32; i++)
		_MrKrabs[i].setPosition(sf::Vector2f(107.5, 7.5));






	//selcect charachter to play ......

	//1 Patrick
	sf::Texture Patrick2;
	if (!Patrick2.loadFromFile("Patrick2.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _Patrick2;
	_Patrick2.setTexture(Patrick2);
	_Patrick2.setPosition(400, 80);
	//2 spongpop
	sf::Texture spongpop2;
	if (!spongpop2.loadFromFile("spongpop2.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _spongpop2;
	_spongpop2.setTexture(spongpop2);
	_spongpop2.setPosition(160, 0);


	//3  Squidward2
	sf::Texture Squidward2;
	if (!Squidward2.loadFromFile("Squidward 2.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _Squidward2;
	_Squidward2.setTexture(Squidward2);
	_Squidward2.setPosition(800, 75);
	//4 Plankton

	sf::Texture Plankton2;
	if (!Plankton2.loadFromFile("Plankton2.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _Plankton2;
	_Plankton2.setTexture(Plankton2);
	_Plankton2.setPosition(100, 260);

	//5 Sandy 

	sf::Texture Sandy2;
	if (!Sandy2.loadFromFile("Sandy3.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _Sandy2;
	_Sandy2.setTexture(Sandy2);
	_Sandy2.setPosition(780, 380);


	//6 MrKrabs
	sf::Texture MrKrabs2;
	if (!MrKrabs2.loadFromFile("MrKrabs.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _MrKrabs2;
	_MrKrabs2.setTexture(MrKrabs2);
	_MrKrabs2.setPosition(420, 420);








	sf::Texture background;
	if (!background.loadFromFile("Background.JPEG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _background;
	_background.setTexture(background);


	sf::Texture circle;
	if (!circle.loadFromFile("Circle.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _circle;
	_circle.setTexture(circle);
	_circle.setPosition(sf::Vector2f(112, 253));
	/*sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("nutfall.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");

	}
	sf::Sound sou;
	sou.setBuffer(buffer);


	sf::Music mus;
	if (!mus.openFromFile("Fly.wav"))
	{
		cout << "load failed" << endl;
		system("pause");

	}
	//mus.play();
	*/
	sf::Texture play;
	if (!play.loadFromFile("Start.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _play;
	_play.setTexture(play);
	_play.setPosition(sf::Vector2f(425, 250));
	sf::Texture options;
	if (!options.loadFromFile("Options.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _options;
	_options.setTexture(options);
	_options.setPosition(sf::Vector2f(425, 300));
	sf::Texture board;
	if (!board.loadFromFile("Board.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _board;
	_board.setTexture(board);
	_board.setPosition(sf::Vector2f(100, 70));

	sf::Texture music;
	if (!music.loadFromFile("Music.JPEG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _music;
	_music.setTexture(music);
	_music.setPosition(sf::Vector2f(425, 300));

	sf::Texture sound;
	if (!sound.loadFromFile("Sound.JPEG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _sound;
	_sound.setTexture(sound);
	_sound.setPosition(sf::Vector2f(425, 500));

	sf::Texture home;
	if (!home.loadFromFile("Home.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _home;
	_home.setTexture(home);
	_home.setPosition(sf::Vector2f(10, 30));
	sf::Texture exit;
	if (!exit.loadFromFile("Exit.PNG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _exit;
	_exit.setTexture(exit);
	_exit.setPosition(sf::Vector2f(425, 450));
	window.clear();
	window.draw(_background);
	window.draw(_play);
	window.draw(_options);
	window.draw(_exit);
	window.display();
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
			{
				window.close();
				exitb = false;

			}
			auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
			auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				if (_exit.getGlobalBounds().contains(translated_pos) && exitb == true) // Rectangle-contains-point check
				{
					window.close();
					exitb = false;
				}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_play.getGlobalBounds().contains(translated_pos) && playb == true)
				{
					window.clear();
					window.draw(_background);
					window.draw(_spongpop2);
					window.draw(_Sandy2);
					window.draw(_MrKrabs2);
					window.draw(_Plankton2);
					window.draw(_Patrick2);
					window.draw(_Squidward2);
					window.draw(_home);
					optionb = false;
					exitb = true;
					window.display();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			
			{

				if (_spongpop2.getGlobalBounds().contains(translated_pos)&& _spongpop3==true)
				{
					_spongpop3 = false;
					exitb == true;
					count++;
					if (count == 2)
					{
						window.close();
					}
				}
				if (_Sandy2.getGlobalBounds().contains(translated_pos)&& _Sandy3==true)
				{
					_Sandy3 = false;
					exitb == true;
					count++;
					if (count == 2)

					{
						window.close();
					}
				}

				if (_Plankton2.getGlobalBounds().contains(translated_pos)&&_Plankton3==true)
				{
					_Plankton3 = false;

					exitb == true;
					count++;
					if (count == 2)
					{
						window.close();
					}

				}
				if (_MrKrabs2.getGlobalBounds().contains(translated_pos)&& _MrKrabs3==true)
				{
					_MrKrabs3 = false;

					exitb == true;
					count++;
					if (count == 2)
					{
						window.close();
					}
				}
				if (_Patrick2.getGlobalBounds().contains(translated_pos)&& _Patrick3==true)

				{
					_Patrick3 = false;

					exitb == true;
					count++;
					if (count == 2)
					{

						window.close();
					}
				}
				if (_Squidward2.getGlobalBounds().contains(translated_pos)&& _Squidward3==true)
				{
					_Squidward3 = false;

					exitb == true;
					count++;
					if (count == 2)
					{
						window.close();
					}
				}
			}


			/* 
			
						if (_options.getGlobalBounds().contains(translated_pos))
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								if ((_music.getGlobalBounds().contains(translated_pos)) && exitb == false)
								{
									mus.stop();
								}
							}*/
			if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				if (_options.getGlobalBounds().contains(translated_pos) && optionb == true)
				{
					playb = false;
					exitb = false;
					window.clear();
					window.draw(_background);
					window.draw(_music);
					window.draw(_sound);
					window.draw(_home);
					window.display();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_home.getGlobalBounds().contains(translated_pos))
				{
					playb = true;
					exitb = false;
					optionb = true;
					window.clear();
					window.draw(_background);
					window.draw(_play);
					window.draw(_options);
					window.draw(_exit);
					window.display();
				}
			}

		}

	

window.clear();
		}
		sf::RenderWindow window2(sf::VideoMode(1024, 768), "Connect 4");
		sf::Event event2;
		window2.clear();
		window2.draw(_background);
		window2.draw(_board);
		//window2.getDefaultView(_background);
		for (int i = 0; i < 32; i++)
		{
			window2.draw(_spongpop[i]);
		}
		window2.display();
		for (int a = 0; a <= 7; a++) {
			for (int b = 0; b <= 7; b++)
				place[a][b] = ' ';
		}
		while (window2.isOpen())
		{

			while (!gamewon&&exitb == true)
			{


				while (window2.pollEvent(event2))
				{
					if (event2.type == sf::Event::Closed)
						window2.close();

					if (player == 15)
					{
						window2.draw(_background);
						window2.draw(_board);
						window2.draw(_spongpop[spongies]);




						if (event2.type == sf::Event::KeyPressed)
						{
							if (event2.key.code == sf::Keyboard::Right)
							{
								if (7 > row)
								{

									window2.draw(_background);
									window2.draw(_board);
									_spongpop[spongies].move(sf::Vector2f(90, 0));


									window2.draw(_spongpop[spongies]);
									window2.display();

									++row;
									cout << row;
								}
							}


							if (event2.key.code == sf::Keyboard::Left)
							{

								if (0 < row)
								{
									window2.draw(_background);
									window2.draw(_board);
									_spongpop[spongies].move(sf::Vector2f(-90, 0));
									window2.draw(_spongpop[spongies]);
									window2.display();
									--row;
									cout << row;

								}
							}

							if (event2.key.code == sf::Keyboard::Enter)
							{
								col = drop(row, player, _spongpop[spongies], _patrick[spongies]);//drop the player store the row in hold2

								if (col == -1)
								{
									cout << "Colomn is full\nPlease enter another number between 1 and 7:";//if error -1 row is full
									fool = false;

								}

								else {
									gamewon = check(col, row);//check if game is 
									/*if (gamewon)
									{
										window.clear();
										window2.draw(_background);

									}*/

									row = 0;
									spongies++;//another character has been succesfully placed
								}

							}

						}

						player = 1;

						for (int i = 0; i < 32; i++)
						{
							window2.draw(_patrick[i]);
						}


						for (int i = 0; i < 32; i++)
						{
							window2.draw(_spongpop[i]);

						}
						window2.display();


					}

					else
					{
						if (event2.type == sf::Event::KeyPressed)
						{
							if (event2.key.code == sf::Keyboard::Right)
							{
								if (7 > row)
								{

									window2.draw(_background);
									window2.draw(_board);
									_patrick[spongies].move(sf::Vector2f(88, 0));
									window2.draw(_patrick[spongies]);
									window2.display();

									++row;
									cout << row;
								}
							}
							if (event2.key.code == sf::Keyboard::Left)
							{
								if (0 < row)
								{
									window2.draw(_background);
									window2.draw(_board);
									_patrick[spongies].move(sf::Vector2f(-88, 0));
									window2.draw(_patrick[spongies]);
									window2.display();
									--row;
									cout << row;
								}
							}

							if (event2.key.code == sf::Keyboard::Enter)
							{
								int 	col = drop(row, player, _spongpop[spongies], _patrick[spongies]);//drop the player store the row in hold2
								if (col == -1)
								{
									cout << "Colomn is full\nPlease enter another number between 1 and 7:";//if error -1 row is full


									fool = false;

								}
								else {
									gamewon = check(col, row);//check if game is run
									row = 0;
									spongies++;//another character has been succesfully placed
								}

							}

						}
						player = 15;
						for (int i = 0; i < 32; i++)
						{

							window2.draw(_patrick[i]);

						}
					}

					for (int i = 0; i < 32; i++)
					{
						window2.draw(_spongpop[i]);

					}
					window2.display();

				}


			}
			window2.close();

		}

	return 0;
}

bool check(int a, int b) {
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = place[a][b];
	int i;//vertical
	int ii;//horizontal
		   //check for vertical(|)
	for (i = a + 1; place[i][b] == player && i <= 7; i++, vertical++);//Check down
	for (i = a - 1; place[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	//check for horizontal(-)
	for (ii = b - 1; place[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left
	for (ii = b + 1; place[a][ii] == player && ii <= 7; ii++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for (i = a - 1, ii = b - 1; place[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left
	for (i = a + 1, ii = b + 1; place[i][ii] == player && i <= 7 && ii <= 7; diagonal1++, i++, ii++);//down and right
	if (diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for (i = a - 1, ii = b + 1; place[i][ii] == player && i >= 0 && ii <= 7; diagonal2++, i--, ii++);//up and right
	for (i = a + 1, ii = b - 1; place[i][ii] == player && i <= 7 && ii >= 0; diagonal2++, i++, ii--);//up and left
	if (diagonal2 >= 4) return true;
	return false;
}

int drop(int b, char player, sf::Sprite& _spongpop, sf::Sprite& _patrick)
{

	if (place[0][b] == ' ') {
		int i;
		for (i = 0; place[i][b] == ' '; i++)


			if (i == 7)
			{
				place[i][b] = player;
					if (player == 15)
					{
						_spongpop.move(sf::Vector2f(0, 690));
					}
					else
					{

						_patrick.move(sf::Vector2f(0, 690));
					}
					return i;
				}
			i--;

			 if (i == 6) 
			 {

					place[i][b] = player;
					if (player == 15)
					{

						_spongpop.move(sf::Vector2f(0, 600));
					}
					else
					{

						_patrick.move(sf::Vector2f(0, 600));
					}
					return i;
				}


				if (i == 5) {
				place[i][b] = player;
				if (player == 15)
				{
					_spongpop.move(sf::Vector2f(0, 510));
				}
				else
				{

					_patrick.move(sf::Vector2f(0, 510));
				}
				return i;
			}


		if (i == 4) {

			place[i][b] = player;
			if (player == 15)
			{

				_spongpop.move(sf::Vector2f(0, 420));
			}
			else
			{

				_patrick.move(sf::Vector2f(0, 420));
			}
			return i;
		}




		 if (i == 3) {
			 place[i][b] = player;

			if (player == 15)
			{

				_spongpop.move(sf::Vector2f(0, 330));
			}
			else
			{

				_patrick.move(sf::Vector2f(0, 330));
			}
			return i;
		}

		 if (i == 2) {

			place[i][b] = player;
			if (player == 15)
			{

				_spongpop.move(sf::Vector2f(0, 250));
			}
			else
			{

				_patrick.move(sf::Vector2f(0, 250));
			}
			return i;
		}

		if (i == 1) {

			place[i][b] = player;
			if (player == 15)
			{

				_spongpop.move(sf::Vector2f(0, 170));
			}
			else
			{

				_patrick.move(sf::Vector2f(0, 170));
			}
			return i;
		}

		if (i == 0) {

			place[i][b] = player;
			if (player == 15)
			{

				_spongpop.move(sf::Vector2f(0, 75));
			}
			else
			{

				_patrick.move(sf::Vector2f(0, 75));
			}

			return i;
		}
	}


	else {


		return -1;
	}

}