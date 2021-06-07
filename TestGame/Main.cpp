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

	//States for button/events

	bool aPressed = false;
	bool aReleased = false;
	bool space = false;
	bool returnReleased = false;
	bool leftClick = false;
	bool rightClick = false;
	bool rightArrow = false;
	bool leftArrow = false;

	//Variables
	int numberOfClicks = 0;
	int mouseX = 0, mouseY = 0;
	int rectXPosition = 0;

	//Images
	Texture image1;
	if (image1.loadFromFile("Data/image1.png") == -1)
	{
		return 1;
	}

	Texture cloud;
	if (cloud.loadFromFile("Data/cloud2.png") == -1)
	{
		return 1;
	}

	//Render Shapes

	RectangleShape rect;
	rect.setSize(Vector2f(150, 100));
	rect.setPosition(0, 0);
	rect.setTexture(&cloud);

	CircleShape circle;
	circle.setRadius(50);
	circle.setPosition(400, 300);
	circle.setFillColor(Color::Red);

	//Fonts
	Font font;
	if (font.loadFromFile("Data/InkFree.ttf") == 0)
	{
		return 1;
	}

	//Text
	Text title;
	title.setFont(font);
	title.setCharacterSize(30);
	title.setString("Test Game");
	title.setPosition(350, 100);
	title.setFillColor(Color::Yellow);

	//Sounds
	SoundBuffer JumpBuffer;
	if (JumpBuffer.loadFromFile("Data/Jump.wav") == 0)
	{
		return 1;
	}

	Sound Jump;
	Jump.setBuffer(JumpBuffer);
	Jump.setLoop(true);

	Jump.play();

	//Music
	Music drumLoop;
	if (drumLoop.openFromFile("Data/electro.ogg") == 0)
	{
		return 1;
	}

	drumLoop.setLoop(true);
	drumLoop.play();

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

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
			{
				leftArrow = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left)
			{
				leftArrow = false;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
			{
				rightArrow = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right)
			{
				rightArrow = false;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				space = true;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space)
			{
				space = false;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return)
			{
				returnReleased = true;
			}

			if (event.type == Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				leftClick = true;
			}

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
			{
				rightClick = true;
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

		if (returnReleased == true)
		{
			cout << "Return has been released" << endl;

			returnReleased = false;
		}

		if (leftClick == true)
		{
			numberOfClicks++;

			cout << "Number of Clicks is " << numberOfClicks << endl;

			if (mouseX < 200)
			{
				window.close();

				play = false;
			}

			leftClick = false;
		}

		if (rightClick == true)
		{
			numberOfClicks--;

			cout << "Number of Clicks is " << numberOfClicks << endl;

			rightClick = false;
		}

		if (leftArrow == true && rightArrow == true)
		{
			cout << " Left arrow key and Right arrow key are pressed down together " << endl;

			leftArrow = false;
			rightArrow = false;

		}

		//cout << "Mouse x: " << mouseX << "Mouse y: " << mouseY << endl;

		rectXPosition++;
		rect.setPosition(rectXPosition, 0);

		//RENDERING
		window.clear();
			
		window.draw(rect);
		window.draw(title);
		window.draw(circle);

		window.display();
	}




	// Clean up

	window.close();

	return 0;
}