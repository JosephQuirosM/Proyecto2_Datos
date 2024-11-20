#ifndef APP_H
#define APP_H

#include "Graph.h"
#include "Button.h"
class App
{
private:
//variables
	sf::RenderWindow window;
	sf::Texture imgMap;
	sf::Sprite map;
	Graph graph;
	Button* initDijkstra;
	int firstNode;
	int secordNode;

public:
//Constructor y destructor
	App();
	~App();

//Metodos publicos
	void run();

private:
//Metodos privados
	void eventHandler();
	void update();
	void draw();

};
#endif
