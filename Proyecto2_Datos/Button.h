#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Button
{
private:
	//variables
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	bool visible;

public:
	//Constructor y destructor
	Button();
	Button(float posX, float posY);

	//Metodos publicos
	bool wasClicked(float posX, float posY);
	void draw(sf::RenderWindow& window);
	void setVisible(bool visible);
	bool isVisible();
private:
	//Metodos privados


};
#endif

