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


	//Variables


	//Shapes


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