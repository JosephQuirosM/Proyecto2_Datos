#include "Button.h"


Button::Button()
{
    visible = false;
}

Button::Button(float posX, float posY)
{
    visible = true;
    button.setSize(sf::Vector2f(200.f, 50.f));
    button.setPosition(sf::Vector2f(posX, posY));
	button.setPosition(sf::Vector2f(posX, posY));
	button.setFillColor(sf::Color::White);
	button.setOutlineColor(sf::Color::Black);
	button.setOutlineThickness(2.0f);
	if (!font.loadFromFile("times.ttf")) {
		std::cout << "Error al cargar una fuente de un boton\n";
		exit(-10);
	}
    text.setFont(font);
    text.setString("Iniciar Dijkstra");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    // Centrar el texto sobre el rectángulo
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::FloatRect rectBounds = button.getGlobalBounds();

    text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
    text.setPosition(
        rectBounds.left + rectBounds.width / 2.0f,
        rectBounds.top + rectBounds.height / 2.0f
    );
}

bool Button::wasClicked(float posX, float posY)
{
    if (visible) {
        return button.getGlobalBounds().contains(posX, posY);
    }
    return false;
}

void Button::draw(sf::RenderWindow& window)
{
    if (visible) {
        window.draw(button);
        window.draw(text);
    }
}

void Button::setVisible(bool visible)
{
    this->visible = visible;
}

bool Button::isVisible()
{
    return visible;
}
