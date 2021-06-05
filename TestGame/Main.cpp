#include <iostream>
#include <SFML/Graphics.hpp>

	using namespace sf;
	using namespace std;

int main() {

	RenderWindow window(VideoMode(800, 600), "Sfml Game");
	window.setFramerateLimit(60);

	bool play = true;

	Event event;

	//Game Loop
	while (play == true) 
	{
		// EVENTS
		while (window.pollEvent(event))
		{
			if (event.type  == Event::KeyPressed && event.key.code == Keyboard::A)
			{
				cout << "The A key has been pressed" << endl;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::A)
			{
				cout << "The key has been released" << endl;
			}

			if (event.type == Event::Closed)
			{
				play = false;
			}
		}

		//LOGIC

		//RENDERING
		window.clear();

		window.display();
	}




	// Clean up

	window.close();

	return 0;
}