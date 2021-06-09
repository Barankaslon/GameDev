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

	//States
	bool rButton = false;
	bool leftButton = false;
	bool rightButton = false;
	bool upButton = false;
	bool downButton = false;


	//Variables
	int rectRotation = 0;
	int xVelocity = 0;
	int yVelocity = 0;

	//Shapes
	RectangleShape shape1;
	shape1.setSize(Vector2f(50, 50));
	shape1.setPosition(400, 300);

	RectangleShape shape2;
	shape2.setSize(Vector2f(100, 200));
	shape2.setPosition(200, 200);
	shape2.setFillColor(Color::Red);

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

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::R)
			{
				rButton = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::R)
			{
				rButton = false;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left) leftButton = true;
				if (event.key.code == Keyboard::Right) rightButton = true;
				if (event.key.code == Keyboard::Up) upButton = true;
				if (event.key.code == Keyboard::Down) downButton = true;
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Left) leftButton = false;
				if (event.key.code == Keyboard::Right) rightButton = false;
				if (event.key.code == Keyboard::Up) upButton = false;
				if (event.key.code == Keyboard::Down) downButton = false;
			}

		}

		//LOGIC

		if (rButton == true)
		{
			rectRotation++;
			shape1.setRotation(rectRotation);
		}

		//Movement
		//X axis
		if (rightButton == true)
		{
			xVelocity = 5;
		}

		if (leftButton == true)
		{
			xVelocity = -5;
		}

		if (leftButton == true && rightButton == true)
		{
			xVelocity = 0;
		}

		if (leftButton == false && rightButton == false)
		{
			xVelocity = 0;
		}
		//Y axis
		if (downButton == true)
		{
			yVelocity = 5;
		}

		if (upButton == true)
		{
			yVelocity = -5;
		}

		if (upButton == true && downButton == true)
		{
			yVelocity = 0;
		}

		if (upButton == false && downButton == false)
		{
			yVelocity = 0;
		}

		//Move
		shape1.move(xVelocity, 0);

		if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds()) == true)
		{
			shape1.move(-xVelocity, 0);
		}

		shape1.move(0, yVelocity);

		if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds()) == true)
		{
			shape1.move(-0, -yVelocity);
		}

		//RENDERING
		window.clear();

		window.draw(shape1);
		window.draw(shape2);

		window.display();
	}

	// Clean up

	window.close();

	return 0;
}