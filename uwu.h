#pragma once
#include <SFML/Graphics.hpp>
#include "img.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
/// <summary>
/// all game mechanics
/// </summary>
class uwu
{
private:
	int leftIMG, rightIMG;
	static const int maxSize=32; //i use array so i need to do this here
	int numberRounds,clicks;
	int currentSize,tempSize; 
	sf::Sprite line;
	sf::Texture textLine;
	img imgs[maxSize];
	sf::Texture text[maxSize];
	std::string names[maxSize];
	sf::Font font;
	sf::Text tex1, tex2,numberOfRounds;
	std::vector<int> rejected_numbers;
	std::vector<int> temp_rejected_numbers;
	sf::RenderWindow window;
	bool type;
	bool end;
	bool game;
public:
	uwu();
	void run();
	void update();
	void render();
	void initVariables();
	void initWindow();
	void initTexture();
	void initImages();
	void initText();
	void resetImg();
	int randomImgLeft();
	int randomImgRight();
	void renderImg();
	void checkMousePosition();
	void nextRound();
	void renderChoose();
	void roundCounter();
	bool rejectedImg(int left,int right);
	
};

