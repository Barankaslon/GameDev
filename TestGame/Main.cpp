#include <iostream>
#include <SFML/Graphics.hpp>

	using namespace sf;
	using namespace std;

int main() {

	RenderWindow window(VideoMode(800, 600), "Sfml Game");
	window.setFramerateLimit(60);

	bool play = true;

	//Game Loop
	while (play == true) 
	{
		// EVENTS
		Event event;
		while (window.pollEvent(event))
		{

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