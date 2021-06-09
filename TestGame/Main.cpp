#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

	using namespace sf;
	using namespace std;

int main() {

	RenderWindow window(VideoMode(800, 600), "Sfml TestGame");
	window.setFramerateLimit(60);

	window.setKeyRepeatEnabled(false);

	bool play = true;

	Event event;

	//Fonts
	Font font;
	if (font.loadFromFile("Data/InkFree.ttf") == 0)
	{
		return 1;
	}

	//Images
	Texture tex_pad;
	Texture tex_ball;
	Texture tex_background;
	if (tex_pad.loadFromFile("Data/pad.png") == false)
	{
		return -1;
	}

	if (tex_ball.loadFromFile("Data/ball.png") == false)
	{
		return -1;
	}

	if (tex_background.loadFromFile("Data/background.png") == false)
	{
		return -1;
	}

	//Sounds

	SoundBuffer buff_hit;
	if (buff_hit.loadFromFile("Data/hit.wav") == false)
	{
		return -1;
	}


	//States
	bool up = false;
	bool down = false;

	//Variables
	int yVelociryPad1 = 0;
	int xVelocityBall = 3;
	int yVelocityBall = 3;

	///////////Shapes
	// Background
	RectangleShape background;
	background.setSize(Vector2f(800, 600));
	background.setPosition(0, 0);
	background.setTexture(&tex_background);

	//Pad1
	RectangleShape pad1;
	pad1.setSize(Vector2f(50 ,100));
	pad1.setPosition(50, 250);
	pad1.setTexture(&tex_pad);

	RectangleShape pad2;
	pad2.setSize(Vector2f(50, 100));
	pad2.setPosition(700, 250);
	pad2.setTexture(&tex_pad);

	RectangleShape ball;
	ball.setSize(Vector2f(50, 50));
	ball.setPosition(400, 250);
	ball.setTexture(&tex_ball);


	//Game Loop
	while (play == true) 
	{
		// EVENTS
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				play = false;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
			{
				up = true;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
			{
				down = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
			{
				up = false;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
			{
				down = false;
			}

		}

		//////LOGIC
		if (up == true)
		{
			yVelociryPad1 = -5;
		}

		if (down == true)
		{
			yVelociryPad1 = 5;
		}

		if (up == true && down == true)
		{
			yVelociryPad1 = 0;
		}

		if (up == false && down == false)
		{
			yVelociryPad1 = 0;
		}

		pad1.move(0, yVelociryPad1);

		if (pad1.getPosition().y < 0)
		{
			pad1.setPosition(50, 0);
		}

		if (pad1.getPosition().y > 500)
		{
			pad1.setPosition(50, 500);
		}

		//Ball
		ball.move(xVelocityBall, yVelocityBall);

		if (ball.getPosition().y < 0)
		{
			yVelocityBall = -yVelocityBall;
		}

		if (ball.getPosition().y > 550)
		{
			yVelocityBall = -yVelocityBall;
		}

		//RENDERING
		window.clear();

		window.draw(background);
		window.draw(pad1);
		window.draw(pad2);
		window.draw(ball);

		window.display();
	}

	// Clean up

	window.close();

	return 0;
}