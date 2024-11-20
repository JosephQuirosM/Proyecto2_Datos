#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <stack>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    std::vector<Node> nodes;
public:

    Graph();

    void addNode(float x, float y);
    void addConnection(int from, int to, int cost, bool bidirectional = true);
    void doDijkstra(int startIndex, int endIndex);
    void drawNodes(sf::RenderWindow& window);
    void nodeWasClicked(float posX, float posY, int& firstIndex, int& secondIndex);
private:

    void createPerezzz();
    void createNodes();
    void conectNodes();
    void setIndex(int i, int& firstIndex, int&secondIndex, Node& node);
    std::pair<int, std::vector<int>> dijkstra(int startIndex, int endIndex);
};


#endif