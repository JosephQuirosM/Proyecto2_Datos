#include "Node.h"

Node::Node(float posX, float posY)
{
	float radius = 5;
	point.setRadius(radius);
	point.setPosition( (posX - radius), (posY - radius) );
	point.setFillColor(sf::Color::Red);
}

std::vector<std::pair<int, int>> Node::getConnections()
{
	return connections;
}

void Node::setConnection(int nodeIndex, int cost)
{
	connections.emplace_back(nodeIndex, cost);
}

sf::CircleShape Node::getCircle()
{
	return point;
}

bool Node::wasClicked(float x, float y)
{
	return point.getGlobalBounds().contains(x, y);
}

void Node::setColor(sf::Color color)
{
	point.setFillColor(color);
}

