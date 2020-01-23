#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects

	//rectangle
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color(0, 0, 0, 255));

	//text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}
	text.setFont(font);
	text.setPosition(0, 0);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color(10, 200, 100, 255));



}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	rect.setPosition(sf::Vector2f(window->getSize()) - sf::Vector2f(50,50));
	int rectColorGreen = abs(sin((window->getSize().x + window->getSize().y) / 2000.0) * 255);
	int rectColorRed = abs(cos((window->getSize().x + window->getSize().y) / 2000.0) * 255);
	rect.setFillColor(sf::Color(rectColorRed, rectColorGreen, 0, 255));

	text.setString(std::to_string(rectColorRed) + ", " + std::to_string(rectColorGreen));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}