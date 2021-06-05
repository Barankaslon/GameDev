#include <iostream>
#include <SFML/Graphics.hpp>

	using namespace sf;
	using namespace std;

int main() {

	RenderWindow window(VideoMode(800, 600), "Sfml Game");
	window.setFramerateLimit(60);

	window.setKeyRepeatEnabled(false);

	bool play = true;

	Event event;

	bool aPressed = false;
	bool aReleased = false;

	bool space = false;

	//Game Loop
	while (play == true) 
	{
		// EVENTS
		while (window.pollEvent(event))
		{
			if (event.type  == Event::KeyPressed && event.key.code == Keyboard::A)
			{
				aPressed = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::A)
			{
				aReleased = true;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				space = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space)
			{
				space = false;
			}

			if (event.type == Event::Closed)
			{
				play = false;
			}
		}

		//LOGIC

		if (aPressed == true)
		{
			cout << "The A key has been pressed" << endl;

			aPressed = false;
		}

		if (aReleased == true)
		{
			cout << "The key has been released" << endl;

			aReleased = false;
		}

		if (space == true)
		{
			cout << "SPACE" << endl;
		}

		if (space == false)
		{
			cout << "NOT SPACE" << endl;
		}

		//RENDERING
		window.clear();

		window.display();
	}




	// Clean up

	window.close();

	return 0;
}