#include"pch.h"
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include <iostream>
#include"string"
using namespace std;
using namespace sf;
char place[8][8];
int drop(int b, char player);
bool check(int a, int b);
struct player {

	string name;


}p1,p2;



int main()
{

	cout << "Please Enter your name player1 :" << " ";
	cin >> p1.name;
	cout << "Please Enter your name player2 :" << " ";
	cin >> p2.name;
	bool winner1 = false;
	bool winner2 = false;
	int count = 0;
	int row = 0;
	int draw =0;
	int col = -1;
	char player = 15;
	bool playb = true;
	bool musicb = false;
	bool gamewon = false;
	bool exitb = true;
	bool optionb = true;
	bool _spongpop3 = false;
	bool _Squidward3 = false;
	bool _Patrick3 = false;
	bool _MrKrabs3 = false;
	bool _Plankton3 = false;
	bool _Sandy3 = false;
	bool wer = true;

	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Connect 4");
	sf::CircleShape circle[8][8];
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0, k = 7; j < 8; j++, k--)
			{
				circle[i][j].setFillColor(Color::White);
				circle[i][j].setRadius(40);
				circle[i][j].setPosition(105 + (i * 85), 75 + (k * 85));
			}
	}

	Texture _select_player1;
	Sprite select_player1;

	Texture _select_player2;
	Sprite select_player2;

	sf::Font draw2;
	if (!draw2.loadFromFile("Some Time Later.otf"))
	{

	}
	sf::Text dr;
	dr.setFont(draw2);
	dr.setString("The Game is a draw");
	dr.setCharacterSize(60);
	dr.setPosition(sf::Vector2f(200, 0));

	sf::Font hom;
	if (!hom.loadFromFile("Some Time Later.otf"))
	{

	}
	sf::Text h;
	h.setFont(hom);
	h.setString("Home");
	h.setCharacterSize(45);
	h.setPosition(sf::Vector2f(45, 180));

	sf::Font Winner;
	if (!Winner.loadFromFile("Some Time Later.otf"))
	{

	}
	sf::Text win;
	win.setFont(Winner);
	win.setString("Congratulations you have won");
	win.setCharacterSize(60);
	win.setPosition(sf::Vector2f(150,250));

	sf::Font Player;
	if (!Player.loadFromFile("Some Time Later.otf"))
	{

	}
	sf::Text wi;
	wi.setFont(Player);
	wi.setCharacterSize(60);
	wi.setPosition(sf::Vector2f(450,350));





	//1 spongpop
	sf::Sprite spongpop;
	sf::Texture _spongpop;

	_spongpop.loadFromFile("spongpop.PNG");

	spongpop.setTexture(_spongpop);

	//2 patrick
	sf::Sprite  patrick;
	sf::Texture _patrick;
	_patrick.loadFromFile("Patrick.PNG");
	patrick.setTexture(_patrick);




	//3 Plankton
	sf::Texture _Plankton;
	sf::Sprite  Plankton;
	_Plankton.loadFromFile("Plankton.PNG");
	Plankton.setTexture(_Plankton);




	/// 4 Squidward
	sf::Texture _Squidward;
	Sprite  Squidward;
	_Squidward.loadFromFile("Squidward1.PNG");

	Squidward.setTexture(_Squidward);


	//5 Sandy
	sf::Texture _Sandy;
	_Sandy.loadFromFile("Sandy.PNG");


	Sprite  Sandy;

	Sandy.setTexture(_Sandy);



	//6 MrKrabs
	sf::Texture _MrKrabs;
	_MrKrabs.loadFromFile("MrKrabs2.PNG");
	Sprite  MrKrabs;

	MrKrabs.setTexture(_MrKrabs);

	sf::Texture background2;
	background2.loadFromFile("Background2.jpg");
	Sprite  _background2;

	_background2.setTexture(background2);





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
	_Patrick2.setPosition(400, 100);
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
	if (!background.loadFromFile("Background.JPG"))
	{
		cout << "load failed" << endl;
		system("pause");
	}
	sf::Sprite _background;
	_background.setTexture(background);

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Bubbles.wav"))
	{
	cout << "load failed" << endl;
	system("pause");

	}
	sf::Sound sou;
	sou.setBuffer(buffer);


	sf::Music mus;
	if (!mus.openFromFile("Ready Children.wav"))
	{
	cout << "load failed" << endl;
	system("pause");

	}
	mus.play();
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
	_options.setPosition(sf::Vector2f(425, 315));
	sf::Texture board;
	if (!board.loadFromFile("Board.png"))
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
	_music.setPosition(sf::Vector2f(425, 450));

	sf::Texture home;
	if (!home.loadFromFile("Home.png"))
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
				wer = false;

				window.close();


			}
			auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
			auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				if (_exit.getGlobalBounds().contains(translated_pos) && exitb == true) // Rectangle-contains-point check
				{
					wer = false;

					window.close();



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
					window.draw(h);
					window.draw(_home);
					optionb = false;
					exitb = false;
					playb = false;
					_MrKrabs3 = true;
					_spongpop3 = true;
					_Sandy3 = true;
					_Patrick3 = true;
					_Plankton3 = true;
					_Squidward3 = true;
					window.display();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))

			{

				if (_spongpop2.getGlobalBounds().contains(translated_pos) && _spongpop3 == true)
				{
					_spongpop3 = false;
					count++;
					if (count == 1)
					{
						select_player1 = spongpop;
						_select_player1 = _spongpop;
						_select_player1.loadFromFile("spongpop.PNG");

					}
					else
					{
						_select_player2 = _spongpop;
						select_player2 = spongpop;
						_select_player2.loadFromFile("spongpop.PNG");

					}

					if (count == 2)
					{
						window.close();
					}
				}
				if (_Sandy2.getGlobalBounds().contains(translated_pos) && _Sandy3 == true)
				{
					_Sandy3 = false;
					count++;
					if (count == 1)
					{
						select_player1 = Sandy;
						_select_player1 = _Sandy;
						_select_player1.loadFromFile("Sandy.PNG");

					}
					else
					{
						_select_player2 = _Sandy;
						select_player2 = Sandy;
						_select_player2.loadFromFile("Sandy.PNG");

					}

					if (count == 2)

					{
						window.close();
					}
				}

				if (_Plankton2.getGlobalBounds().contains(translated_pos) && _Plankton3 == true)
				{
					_Plankton3 = false;

					count++;
					if (count == 1)
					{
						select_player1 = Plankton;
						_select_player1 = _Plankton;
						_select_player1.loadFromFile("Plankton.PNG");
					}
					else
					{
						_select_player2 = _Plankton;
						select_player2 = Plankton;
						_select_player2.loadFromFile("Plankton.PNG");
					}

					if (count == 2)
					{
						window.close();
					}

				}
				if (_MrKrabs2.getGlobalBounds().contains(translated_pos) && _MrKrabs3 == true)
				{
					_MrKrabs3 = false;

					count++;
					if (count == 1)
					{
						select_player1 = MrKrabs;
						_select_player1 = _MrKrabs;
						_select_player1.loadFromFile("MrKrabs2.PNG");

					}
					else
					{
						_select_player2 = _MrKrabs;


						select_player2 = MrKrabs;
						_select_player2.loadFromFile("MrKrabs2.PNG");

					}

					if (count == 2)
					{
						window.close();
					}
				}
				if (_Patrick2.getGlobalBounds().contains(translated_pos) && _Patrick3 == true)

				{
					_Patrick3 = false;
					count++;
					if (count == 1)
					{
						select_player1 = patrick;
						_select_player1 = _patrick;
						_select_player1.loadFromFile("Patrick.PNG");

					}
					else

					{
						_select_player2 = _patrick;
						select_player2 = patrick;
						_select_player2.loadFromFile("Patrick.PNG");

					}

					if (count == 2)
					{

						window.close();
					}
				}
				if (_Squidward2.getGlobalBounds().contains(translated_pos) && _Squidward3 == true)
				{
					_Squidward3 = false;

					count++;
					if (count == 1)
					{
						select_player1 = Squidward;
						_select_player1 = _Squidward;
						_select_player1.loadFromFile("Squidward1.PNG");
					}
					else
					{
						_select_player2 = _Squidward;
						select_player2 = Squidward;
						_select_player2.loadFromFile("Squidward1.PNG");
					}

					if (count == 2)
					{
						window.close();
					}
				}
			}


			
						
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
						if ((_music.getGlobalBounds().contains(translated_pos))&& musicb==true && exitb == false)
						{
						mus.stop();
						}
						}
						
			if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				if (_options.getGlobalBounds().contains(translated_pos) && optionb == true)
				{
					playb = false;
					musicb = true;
					exitb = false;
					window.clear();
					window.draw(_background);
					window.draw(_music);
					window.draw(_home);
					window.draw(h);
					window.display();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_home.getGlobalBounds().contains(translated_pos))
				{
					playb = true;
					exitb = true;
					optionb = true;
					window.clear();
					window.draw(_background);
					window.draw(_play);
					window.draw(_options);
					window.draw(_exit);
					window.display();
				}
			}
			window.clear();
		}
	}
	sf::RenderWindow window2(sf::VideoMode(1024, 768), "Connect 4");
	sf::Event event2;
	for (int a = 0; a <= 7; a++) {
		for (int b = 0; b <= 7; b++)
			place[a][b] = ' ';
	}
	while (window2.isOpen())
	{
		
		auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
		auto translated_pos = window.mapPixelToCoords(mouse_pos);
		if (wer == false)
		{
			window2.close();
		}
		window2.clear();
		window2.draw(_background2);
		window2.draw(_board);
				for (int a = 0; a <= 7; a++)
		{
			for (int b = 0; b <= 7; b++)
			{
				window2.draw(circle[a][b]);
			}
		}

		if (player == 15)
		{
			select_player1.setPosition(circle[row][0].getPosition().x, 5);
			window2.draw(select_player1);
		}
		else
		{
			select_player2.setPosition(circle[row][0].getPosition().x, 5);
			window2.draw(select_player2);
		}


		if (!gamewon)
		{

			if (window2.pollEvent(event2))
			{
				if (event2.type == sf::Event::Closed)
					window2.close();

				if (player == 15)
				{
					if (event2.type == sf::Event::KeyPressed)
					{
						if (event2.key.code == sf::Keyboard::Right)
						{
							if (7 > row)
							{

								++row;
								//cout << row;
							}
						}
						if (event2.key.code == sf::Keyboard::Left)
						{

							if (0 < row)
							{
								--row;
								//	cout << row;

							}
						}

						if (event2.key.code == sf::Keyboard::Enter)
						{
							col = drop(row, player);//drop the player store the row in hold2

							if (col == -1)
							{
								cout << "Colomn is full";//if error -1 row is full
	
							}

							else {
								draw++;
								if (draw == 64)
								{
									window2.clear();
									window2.draw(_background);
									window2.draw(dr);
								}
								sou.play();
								gamewon = check(row, col);//check if game is 
								if (gamewon)
								{
									window2.clear();
									window2.draw(_background);
									window2.draw(win);
									wi.setString(p1.name);
									window2.draw(wi);
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										if (_home.getGlobalBounds().contains(translated_pos))
										window2.close();


								}
								circle[row][col].setTexture(&_select_player1);
								row = 0;
								player = 1;
							}

						}

					}






				}

				else
				{
					if (event2.type == sf::Event::KeyPressed)
					{
						if (event2.key.code == sf::Keyboard::Right)
						{
							if (7 > row)
							{

								++row;
								//cout << row;
							}
						}
						if (event2.key.code == sf::Keyboard::Left)
						{
							if (0 < row)
							{

								--row;
								//	cout << row;
							}
						}

						if (event2.key.code == sf::Keyboard::Enter)
						{
							col = drop(row, player);//drop the player store the row in hold2
							if (col == -1)
							{
								cout << "Colomn is full";//if error -1 row is full


							
							}
							else {
								draw++;
								sou.play();
								gamewon = check(row, col);//check if game is run
								if (gamewon)
								{
									window2.clear();
									window2.draw(_background);
									window2.draw(win);
									wi.setString(p2.name);
									window2.draw(wi);
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										if (_home.getGlobalBounds().contains(translated_pos))
										window2.close();
								}

								circle[row][col].setTexture(&_select_player2);
								if (draw == 64)
								{
									window2.clear();
									window2.draw(_background);
									window2.draw(dr);
								}
								row = 0;
								player = 15;
							}

						}

					}



				}
window2.display();
			}


		}
		
		
	}

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
	for (ii = b - 1; place[a][
		ii] == player && ii >= 0; ii--, horizontal++);//Check left
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

int drop(int b, char player)
{
	for (int i = 0; i < 8; i++)
	{
		if (place[b][i] == ' ')
		{
			place[b][i] = player;
			return i;
		}
	}
	return -1;


}