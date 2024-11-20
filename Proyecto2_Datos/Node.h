#ifndef NODE_H
#define NODE_H
#include "SFML/Graphics.hpp"

class Node 
{
private:
    sf::CircleShape point;
    std::vector<std::pair<int, int>> connections;

public:
    Node(float posX, float posY);

    std::vector<std::pair<int, int>> getConnections();
    void setConnection(int nodeIndex, int cost);
    sf::CircleShape getCircle();
    bool wasClicked(float x, float y);
    void setColor(sf::Color color);
};
#endif