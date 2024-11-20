#include "App.h"

App::App()
{
	initDijkstra = new Button(700.f, 100.f);
	window.create(sf::VideoMode(963, 813), "Weiz TEMU");
	imgMap.loadFromFile("map/map.png");
	map.setTexture(imgMap);

	firstNode = -1;
	secordNode = -1;
}

App::~App()
{
}

void App::run()
{
	while (window.isOpen())
	{
		eventHandler();
		update();
		window.clear(sf::Color(128, 128, 128));
		draw();
		window.display();
	}
}

void App::eventHandler()
{
    sf::Event event;
    while (window.pollEvent(event))
    {

		if (event.type == sf::Event::Closed) {
			window.close();
		}

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            std::cout << "Clic izquierdo detectado en: (" << x << ", " << y << ")" << std::endl;
			graph.nodeWasClicked(x, y, firstNode, secordNode);

			if (initDijkstra->wasClicked(x, y)) {

				if (firstNode != -1 && secordNode != -1) {
					graph.doDijkstra(firstNode, secordNode);
				}
			}
        }

		
    }
}

void App::update()
{
}

void App::draw()
{
	window.draw(map);
	graph.drawNodes(window);
	initDijkstra->draw(window);
}
