#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class img
{
private:
	sf::Texture text;
	sf::Sprite sprite;
	sf::Text txt;
	sf::Font font;
public:
	img();
	void initText();
	void setTexture(sf::Texture text,std::string name);
	friend class uwu;
};

