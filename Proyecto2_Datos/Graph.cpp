#include "Graph.h"

Graph::Graph()
{
    createPerezzz();
}

void Graph::addNode(float x, float y)
{
	nodes.emplace_back(x, y);
}

void Graph::addConnection(int from, int to, int cost, bool bidirectional)
{
    nodes[from].setConnection(to, cost);
    if (bidirectional) {
        nodes[to].setConnection(from, cost);
    }
}

std::pair<int, std::vector<int>> Graph::dijkstra(int startIndex, int endIndex)
{
    int n = nodes.size();
    std::cout << n <<"\n";

    if (n == 0) {
        std::cerr << "Error: El grafo no tiene nodos.\n";
        return { INF, {} };
    }

    if (startIndex < 0 || startIndex >= n || endIndex < 0 || endIndex >= n) {
        std::cerr << "Error: Índices fuera de rango.\n";
        return { INF, {} };
    }

    std::vector<int> distances(n, INF);
    std::vector<int> predecessors(n, -1);
    distances[startIndex] = 0;

    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>> pq;
    pq.push({ 0, startIndex });

    while (!pq.empty()) {
        std::pair<int, int> current = pq.top();
        pq.pop();

        int currentDist = current.first;
        int currentNodeIndex = current.second;

        if (currentDist > distances[currentNodeIndex]) continue;

        for (const auto& neighbor : nodes[currentNodeIndex].getConnections()) {
            int neighborIndex = neighbor.first;
            int cost = neighbor.second;

            int newDist = currentDist + cost;
            if (newDist < distances[neighborIndex]) {
                distances[neighborIndex] = newDist;
                predecessors[neighborIndex] = currentNodeIndex;
                pq.push({ newDist, neighborIndex });
            }
        }
    }

    std::vector<int> path;
    if (distances[endIndex] != INF) {
        for (int at = endIndex; at != -1; at = predecessors[at]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());
    }

    return { distances[endIndex], path };
}

void Graph::drawNodes(sf::RenderWindow& window)
{
    for (Node& node : nodes) {
        window.draw(node.getCircle());
    }
}

void Graph::nodeWasClicked(float posX, float posY, int& firstIndex, int& secondIndex)
{
    int i = 0;

    for (Node& node : nodes) {
        if (node.wasClicked(posX, posY)) {
            setIndex(i, firstIndex, secondIndex, node);
            break;
        }
        i++;
    }

    std::cout << "primer punto: " << firstIndex;
    std::cout << "\nsegundo punto: " << secondIndex;
    std::cout << "\n--------------------------\n";
}

void Graph::createPerezzz()
{
    createNodes();
    conectNodes();
}

void Graph::createNodes()
{
    //Agregar nodos al grafo
    addNode(356, 25); // nodo 1
    addNode(302, 84); // nodo 2
    addNode(285, 176); // nodo 3
    addNode(354, 145); // nodo 4
    addNode(280, 208); // nodo 5
    addNode(319, 219); // nodo 6
    addNode(376, 194); // nodo 7
    addNode(431, 170); // nodo 8
    addNode(265, 289); // nodo 9
    addNode(377, 252); // nodo 10
    addNode(455, 207); // nodo 11
    addNode(231, 337); // nodo 12
    addNode(304, 300); // nodo 13
    addNode(345, 300); // nodo 14
    addNode(379, 314); // nodo 15
    addNode(429, 275); // nodo 16
    addNode(499, 273); // nodo 17
    addNode(486, 296); // nodo 18
    addNode(531, 333); // nodo 19
    addNode(413, 325); // nodo 20
    addNode(468, 347); // nodo 21
    addNode(493, 358); // nodo 22
    addNode(520, 367); // nodo 23
    addNode(484, 383); // nodo 24
    addNode(458, 373); // nodo 25
    addNode(448, 399); // nodo 26
    addNode(502, 419); // nodo 27
    addNode(601, 460); // nodo 28
    addNode(579, 510); // nodo 29
    addNode(396, 378); // nodo 30
    addNode(361, 366); // nodo 31
    addNode(340, 361); // nodo 32
    addNode(291, 353); // nodo 33
    addNode(212, 358); // nodo 34
    addNode(276, 384); // nodo 35
    addNode(330, 407); // nodo 36
    addNode(377, 426); // nodo 37
    addNode(403, 436); // nodo 38
    addNode(431, 448); // nodo 39
    addNode(481, 468); // nodo 40
    addNode(529, 490); // nodo 41
    addNode(509, 541); // nodo 42
    addNode(542, 553); // nodo 43
    addNode(551, 534); // nodo 44
    addNode(559, 562); // nodo 45
    addNode(460, 520); // nodo 46
    addNode(437, 573); // nodo 47
    addNode(488, 592); // nodo 48
    addNode(469, 639); // nodo 49
    addNode(463, 659); // nodo 50
    addNode(512, 681); // nodo 51
    addNode(478, 771); // nodo 52
    addNode(455, 760); // nodo 53
    addNode(390, 730); // nodo 54
    addNode(336, 704); // nodo 55
    addNode(350, 654); // nodo 56
    addNode(364, 608); // nodo 57
    addNode(399, 619); // nodo 58
    addNode(418, 625); // nodo 59
    addNode(402, 606); // nodo 60
    addNode(378, 556); // nodo 61
    addNode(399, 498); // nodo 62
    addNode(383, 488); // nodo 63
    addNode(357, 478); // nodo 64
    addNode(334, 541); // nodo 65
    addNode(311, 619); // nodo 66
    addNode(249, 592); // nodo 67
    addNode(280, 519); // nodo 68
    addNode(242, 608); // nodo 69
    addNode(307, 457); // nodo 70
    addNode(266, 442); // nodo 71
    addNode(251, 433); // nodo 72
    addNode(175, 401); // nodo 73
    addNode(147, 432); // nodo 74
    addNode(109, 474); // nodo 75
    addNode(144, 499); // nodo 76
    addNode(200, 481); // nodo 77
    addNode(176, 527); // nodo 78
    addNode(243, 503); // nodo 79
    addNode(220, 546); // nodo 80
    addNode(114, 544); // nodo 81
    addNode(47, 542); // nodo 82
}

void Graph::conectNodes()
{
    // Conectar los nodos con costos
    //addConnection(a, b, c); conectar 'a' con 'b' con un costo 'c' en ambos sentidos
    addConnection(0, 1, 60);
    addConnection(0, 7, 120);
    addConnection(1, 2, 65);
    addConnection(1, 3, 60);
    addConnection(2, 3, 50);
    addConnection(2, 4, 20);
    addConnection(3, 6, 40);
    addConnection(4, 5, 30);
    addConnection(4, 8, 60);
    addConnection(5, 6, 45);
    addConnection(5, 13, 60);
    addConnection(6, 7, 45);
    addConnection(6, 9, 40);
    addConnection(7, 10, 35);
    addConnection(8, 11, 40);
    addConnection(8, 12, 30);
    addConnection(9, 15, 40);
    addConnection(10, 15, 50);
    addConnection(10, 16, 55);
    addConnection(11, 32, 45);
    addConnection(11, 33, 20);
    addConnection(13, 31, 45);
    addConnection(13, 14, 25);
    addConnection(14, 19, 25);
    addConnection(14, 30, 40);
    addConnection(15, 19, 40);
    addConnection(15, 17, 45);
    addConnection(16, 17, 20);
    addConnection(16, 18, 50);
    addConnection(17, 20, 40);
    addConnection(18, 22, 30);
    addConnection(18, 27, 110);
    addConnection(19, 29, 40);
    addConnection(19, 20, 45);
    addConnection(20, 21, 20);
    addConnection(20, 24, 20);
    addConnection(21, 22, 20);
    addConnection(21, 23, 20);
    addConnection(22, 26, 40);
    addConnection(23, 24, 20);
    addConnection(24, 25, 20);
    addConnection(25, 29, 40);
    addConnection(25, 38, 40);
    addConnection(25, 26, 40);
    addConnection(26, 39, 30);
    addConnection(26, 27, 60);
    addConnection(27, 28, 30);
    addConnection(28, 40, 30);
    addConnection(28, 44, 30);
    addConnection(29, 30, 20);
    addConnection(29, 36, 25, false);
    addConnection(30, 31, 10);
    addConnection(31, 32, 40);
    addConnection(31, 35, 35);
    addConnection(32, 34, 25);
    addConnection(33, 72, 40);
    addConnection(33, 34, 50);
    addConnection(34, 35, 45);
    addConnection(34, 71, 40);
    addConnection(35, 69, 40);
    addConnection(35, 36, 40);
    addConnection(36, 63, 40);
    addConnection(36, 37, 20);
    addConnection(37, 38, 20);
    addConnection(38, 39, 40);
    addConnection(39, 40, 40, false);
    addConnection(39, 45, 40);
    addConnection(40, 41, 40);
    addConnection(41, 45, 40);
    addConnection(41, 42, 25);
    addConnection(42, 43, 20);
    addConnection(42, 44, 15);
    addConnection(44, 50, 90);
    addConnection(45, 46, 40, false);
    addConnection(45, 61, 50);
    addConnection(46, 60, 45);
    addConnection(46, 58, 45);
    addConnection(46, 47, 40);
    addConnection(47, 41, 40, false);
    addConnection(47, 41, 35);
    addConnection(48, 49, 15);
    addConnection(48, 58, 40);
    addConnection(49, 50, 40);
    addConnection(50, 51, 70);
    addConnection(51, 52, 20);
    addConnection(52, 49, 70, false);
    addConnection(52, 53, 50);
    addConnection(53, 58, 80);
    addConnection(53, 54, 40);
    addConnection(54, 81, 240);
    addConnection(54, 55, 40);
    addConnection(55, 56, 35);
    addConnection(55, 68, 85);
    addConnection(56, 60, 40);
    addConnection(56, 57, 30);
    addConnection(57, 58, 15);
    addConnection(57, 59, 10);
    addConnection(60, 61, 45);
    addConnection(61, 62, 10);
    addConnection(62, 63, 20);
    addConnection(62, 37, 40, false);
    addConnection(63, 69, 40);
    addConnection(63, 64, 50);
    addConnection(64, 65, 60);
    addConnection(64, 67, 40);
    addConnection(65, 66, 50);
    addConnection(66, 68, 10);
    addConnection(66, 67, 60);
    addConnection(67, 78, 30);
    addConnection(67, 69, 50);
    addConnection(68, 80, 100);
    addConnection(69, 70, 30);
    addConnection(70, 71, 10);
    addConnection(70, 78, 45);
    addConnection(71, 72, 60);    
    addConnection(72, 73, 30);
    addConnection(73, 74, 40);
    addConnection(73, 76, 50);
    addConnection(74, 81, 65);
    addConnection(74, 75, 30);
    addConnection(76, 77, 40);
    addConnection(78, 79, 40);
}

void Graph::setIndex(int i, int& firstIndex, int& secondIndex, Node& node)
{
    if (firstIndex == -1) {
        node.setColor(sf::Color::Green);
        firstIndex = i;
        return;
    }

    if (firstIndex == i) {
        node.setColor(sf::Color::Red);
        firstIndex = -1;
        return;
    }

    if (secondIndex == -1) {
        node.setColor(sf::Color::Green);
        secondIndex = i;
        return;
    }

    if (secondIndex == i) {
        node.setColor(sf::Color::Red);
        secondIndex = -1;
        return;
    }
}

void Graph::doDijkstra(int startIndex, int endIndex)
{

    std::pair<int, std::vector<int>> result = dijkstra(startIndex, endIndex);

    // Obtener la distancia y el camino desde el resultado
    int distance = result.first;  // La distancia mínima
    std::vector<int> path = result.second;  // El camino

    // Mostrar el resultado
    if (distance != INF) {
        std::cout << "\nDistancia minima de " << startIndex << " a " << endIndex << ": " << distance << "\n";
        std::cout << "Camino: ";
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "\nNo hay camino de " << startIndex << " a " << endIndex << "\n";
    }

}
