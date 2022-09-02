#include "img.h"
img::img()
{
	this->initText();
}
/// <summary>
/// init text below the picture
/// </summary>
void img::initText()
{
	font.loadFromFile("Fonts/arial.ttf");
	txt.setFont(font);
	txt.setCharacterSize(24); // in pixels, not points!
	txt.setFillColor(sf::Color::Red);
}

void img::setTexture(sf::Texture text, std::string name)
{
	this->text = text;
	this->sprite.setTexture(this->text);
	this->txt.setString(name);
}


