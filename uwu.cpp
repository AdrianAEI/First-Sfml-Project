#include "uwu.h"

uwu::uwu()
{
	this->initVariables();
	this->initWindow();
	this->initText();
}

void uwu::initWindow()
{
	this->window.create(sf::VideoMode(1280, 720), "Uwufufu");
	this->window.setFramerateLimit(60);
}
void uwu::initTexture() //now is for 32 but easy can make this for 4,8,16,64...
{
	 //texture and text
		text[0].loadFromFile("UwuTextures/Gryma.png");
		text[1].loadFromFile("UwuTextures/Paulina.png");
		text[2].loadFromFile("UwuTextures/Patrycja.png");
		text[3].loadFromFile("UwuTextures/Falfus.png");
		text[4].loadFromFile("UwuTextures/Natalia.png");
		text[5].loadFromFile("UwuTextures/Smuga.png");
		text[6].loadFromFile("UwuTextures/Wierzchowska.png");
		text[7].loadFromFile("UwuTextures/Weronika.png");
		text[8].loadFromFile("UwuTextures/Kornelia.png");
		text[9].loadFromFile("UwuTextures/Vervio.png");
		text[10].loadFromFile("UwuTextures/Asia.png");
		text[11].loadFromFile("UwuTextures/Kasia.png");
		text[12].loadFromFile("UwuTextures/Ola.png");
		text[13].loadFromFile("UwuTextures/Olga.png");
		text[14].loadFromFile("UwuTextures/Emilka.png");
		text[15].loadFromFile("UwuTextures/Wika.png");
		text[16].loadFromFile("UwuTextures/Bochenek.png");
		text[17].loadFromFile("UwuTextures/Boryczewska.png");
		text[18].loadFromFile("UwuTextures/Klaudia.png");
		text[19].loadFromFile("UwuTextures/Kinga.png");
		text[20].loadFromFile("UwuTextures/Magda.png");
		text[21].loadFromFile("UwuTextures/Karolina.png");
		text[22].loadFromFile("UwuTextures/Julia.png");
		text[23].loadFromFile("UwuTextures/Stacipa.png");
		text[24].loadFromFile("UwuTextures/Strzelska.png");
		text[25].loadFromFile("UwuTextures/Mosur.png");
		text[26].loadFromFile("UwuTextures/Werka.png");
		text[27].loadFromFile("UwuTextures/Rogowska.png");
		text[28].loadFromFile("UwuTextures/Bobryk.png");
		//names
		names[0] = "Gryma";
		names[1] = "Paulina";
		names[2] = "Patrycja";
		names[3] = "Falfus";
		names[4] = "Natalia";
		names[5] = "Smuga";
		names[6] = "Wierzchowska";
		names[7] = "Weronika";
		names[8] = "Kornelia";
		names[9] = "Vervio";
		names[10] = "Asia";
		names[11] = "Kasia";
		names[12] = "Ola";
		names[13] = "Olga";
		names[14] = "Emilka";
		names[15] = "Wika";
		names[16] = "Bochenek";
		names[17] = "Boryczewska";
		names[18] = "Klaudia";
		names[19] = "Kinga";
		names[20] = "Magda";
		names[21] = "Karolina";
		names[22] = "Julia";
		names[23] = "Staciwa";
		names[24] = "Strzelska";
		names[25] = "Mosur";
		names[26] = "Werka";
		names[27] = "Rogowska";
		names[28] = "Bobryk";
		//choose a category of quiz game 
		if (this->type)
		{
			text[29].loadFromFile("UwuTextures/Gruszka.png");
			text[30].loadFromFile("UwuTextures/Marta.png");
			text[31].loadFromFile("UwuTextures/Curley.png");
			names[29] = "Gruszka";
			names[30] = "Marta";
			names[31] = "Curley";
		}
		else
		{
			text[29].loadFromFile("UwuTextures/Oliwia.png");
			text[30].loadFromFile("UwuTextures/Fujarska.png");
			text[31].loadFromFile("UwuTextures/Kluczna.png");
			names[29] = "Oliwia";
			names[30] = "Fujarska";
			names[31] = "Kluczna";
		}
}
void uwu::initImages()
{
	for (int i = 0; i < maxSize; i++)
	{		
		imgs[i].setTexture(text[i],names[i]);
	}
	this->resetImg();//set random img to left and right
}

void uwu::initText()
{
	font.loadFromFile("Fonts/arial.ttf");
	tex1.setFont(font);
	tex1.setFillColor(sf::Color::Blue);
	tex1.setCharacterSize(36); // in pixels
	tex1.setString("The prettiest girl (without girlfriends)");
	tex1.setPosition(sf::Vector2f(this->window.getSize().x / 2-275.f, 550));
	tex2.setFont(font);
	tex2.setFillColor(sf::Color::Cyan);
	tex2.setCharacterSize(36);
	tex2.setString("The prettiest girl");
	tex2.setPosition(sf::Vector2f(this->window.getSize().x / 2-150.f, 100));
	numberOfRounds.setFont(font);
	numberOfRounds.setCharacterSize(36);
	numberOfRounds.setPosition(sf::Vector2f(this->window.getSize().x/2-25.f, 75.f));
}

void uwu::resetImg() //must to save what numbers are not free and clear after one stage
{
	this->leftIMG = 0;
	this->rightIMG = 0;
	while (!end&&leftIMG == rightIMG||rejectedImg(leftIMG,rightIMG))
	{
		leftIMG = randomImgLeft();
		rightIMG = randomImgRight();
		if (rejected_numbers.size() == maxSize)//must leave a while
		{
			this->nextRound();
		}
	}
	if (!end)
	{
		imgs[leftIMG].sprite.setPosition(75.f, 150.f);
		imgs[leftIMG].txt.setPosition(this->window.getSize().x / 4-50.f, 650.f);
		imgs[rightIMG].sprite.setPosition(750.f, 150.f);
		imgs[rightIMG].txt.setPosition(this->window.getSize().x * 0.75-5.f, 650.f);
	}
	else 
	{//w/e bcs its only one img at the end
		imgs[rightIMG].sprite.setPosition(375.f, 150.f);
		imgs[rightIMG].txt.setPosition(this->window.getSize().x/2-175.f, 650.f);
		imgs[rightIMG].txt.setFillColor(sf::Color::Green);
		imgs[rightIMG].txt.setString("The winner is " + imgs[rightIMG].txt.getString());
	}
	//only one time one img
	rejected_numbers.push_back(leftIMG);
	rejected_numbers.push_back(rightIMG);
}

int uwu::randomImgLeft()
{
	return rand() % maxSize;
}
int uwu::randomImgRight()
{
	return rand() % maxSize;
}
void uwu::run()
{
	while (this->window.isOpen())
	{
		this->update();
		this->render();
	}
}
void uwu::update()
{
	sf::Event e;
	while (this->window.pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!end)
		{
			this->checkMousePosition();
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}
	}
}
void uwu::render()
{
	this->window.clear();
	if (game)
		this->renderImg();
	else
		this->renderChoose();
	this->window.display();
}
void uwu::initVariables()
{
	this->leftIMG = 0;
	this->rightIMG = 0;
	this->currentSize = this->maxSize / 2;
	this->tempSize = this->maxSize / 4;
	this->numberRounds = this->currentSize;
	this->clicks = 0;
	this->end = false;
	this->game = false;
	textLine.loadFromFile("UwuTextures/Line.png");
	line.setTexture(textLine);
	line.setPosition(0.f, 300.f);
}
void uwu::renderImg()
{
	if (!end)
	{
		this->window.draw(numberOfRounds);
		this->window.draw(imgs[leftIMG].sprite);
		this->window.draw(imgs[leftIMG].txt);
		this->window.draw(imgs[rightIMG].sprite);
		this->window.draw(imgs[rightIMG].txt);
	}
	else
	{
		this->window.draw(imgs[rightIMG].sprite);
		this->window.draw(imgs[rightIMG].txt);
	}
}

void uwu::checkMousePosition()
{
	sf::Vector2i position = sf::Mouse::getPosition(window);
	if (game)
	{
		if (position.x >= 748&& position.x <= 1232 && position.y >= 148 && position.y <= 684)
		{
			std::cout << "Right side" << std::endl;
			temp_rejected_numbers.push_back(leftIMG);
			this->resetImg();
			this->roundCounter();
		}
		else if (position.x >= 74 && position.x <= 560 && position.y >= 148 && position.y <= 684)
		{
			std::cout << "Left side" << std::endl;
			temp_rejected_numbers.push_back(rightIMG);
			this->resetImg();
			this->roundCounter();
		}
		else
			std::cout << "You didnt click on the pictures" << std::endl;
	}
	else
	{
		if (position.y > 420 && position.y <= 1080)
		{
			std::cout << "down" << std::endl;
			this->type = 1;
			this->game=true;
			//must be here to dont start game when click out of range
			this->initTexture();
			this->initImages();
			this->roundCounter();
		}
		else if (position.y <= 380)
		{
			std::cout << "up" << std::endl;
			this->type = 0;
			this->game=true;
			this->initTexture();
			this->initImages();
			this->roundCounter();
		}
		else
			std::cout << "Out of the window" << std::endl;
	}
}

void uwu::nextRound() 
{
	//display what round it is
	if(tempSize)
	std::cout<<std::endl << "all taken"<<std::endl;
	//the end of game
	if (temp_rejected_numbers.size() == maxSize - 1)
	{
		end = true;
	}
	rejected_numbers.clear();
	
	for (int i = 0; i < currentSize; i++) //from 8 to 4...
	{
		rejected_numbers.push_back(temp_rejected_numbers[i]);
	}

	currentSize+=tempSize;
	tempSize *= 0.5;
}

void uwu::renderChoose()
{
	this->window.draw(tex1);
	this->window.draw(line);
	this->window.draw(tex2);
}
/// <summary>
/// i have to count what round it is 
/// </summary>
void uwu::roundCounter()
{
	clicks++;
	if (clicks == numberRounds+1)
	{
		clicks = 1;
		numberRounds *= 0.5;
	}
	//set text
	numberOfRounds.setString(std::to_string(clicks) + "/" + std::to_string(numberRounds));
}
bool uwu::rejectedImg(int left, int right)
{
	for (auto x : rejected_numbers)
	{
		if (x == left || x == right)
			return true;
	}
	return false;
}
