#ifndef _LAB3_GRAPH_H
#define _LAB3_GRAPH_H

#include <iostream>
#include <vector>

class Graph {
    std::vector<int> *la;
    int nrNodes, nrEdges;
    int *degrees;
public:
    Graph() { }
    Graph(int nrNodes) { this->nrNodes = nrNodes; la = new std::vector<int>[this->nrNodes + 1]; degrees = nullptr; }

    void initDegreesVector(int);
    void setNodeDegree(int, int);
    int getNodeDegree(int);
    bool hasNoVisitedNodes();
    int sumOfDegrees();
    void constructGraph();

    void showDegrees();
    void printGraph(std::ostream&);
};

#endif