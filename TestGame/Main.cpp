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

	//Variables
	int rectRotation = 0;

	//Shapes
	RectangleShape shape1;
	shape1.setSize(Vector2f(50, 50));
	shape1.setPosition(400, 300);

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
		}

		//LOGIC

		if (rButton == true)
		{
			rectRotation++;
			shape1.setRotation(rectRotation);
		}

		//RENDERING
		window.clear();

		window.draw(shape1);

		window.display();
	}

	// Clean up

	window.close();

	return 0;
}