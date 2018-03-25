#include "headers/graph.hpp"

#include <iostream>
#include <stdlib.h>

void Graph::initDegreesVector(int nrNodes = 0) {
    this->degrees = new int[nrNodes + 1];
    for(int i=0; i<=nrNodes; i++)
        this->degrees[i] = 0;
}

void Graph::setNodeDegree(int node, int d) {
    this->degrees[node] = d;
}

int Graph::getNodeDegree(int node) {
    return this->degrees[node];
}

bool Graph::hasNoVisitedNodes() {
    for(int i=1; i<=this->nrNodes; i++)
        if(this->degrees[i] != 0) return true;
    return false;
}

int Graph::sumOfDegrees() {
    int s = 0;
    for(int x=1; x<=this->nrNodes; x++)
        s = s + getNodeDegree(x);
    return s;
}

/*int cmpInt(const void* a, const void* b) {
    return (*(int*)a > *(int*)b)?1:((*(int*)a == *(int*)b)?0:-1);
}*/

void Graph::constructGraph() {
    int node = 1;
    while(hasNoVisitedNodes()) {
        //qsort(&this->degrees[node], this->nrNodes, sizeof(int), cmpInt);

        int d = getNodeDegree(node);
        for(int offset=1; offset<=d; offset++) {
            setNodeDegree(node + offset, getNodeDegree(node + offset) - 1);
            la[node].push_back(node+offset); la[node+offset].push_back(node);
        }
        setNodeDegree(node, 0); 
        while(getNodeDegree(node) == 0) node++;
    }
}

void Graph::showDegrees() {
    for(int x = 1; x<=this->nrNodes; x++) {
        std::cout<<getNodeDegree(x)<<" ";
    }
    std::cout<<"\n";
}

void Graph::printGraph(std::ostream& out) {
    for(int x = 1; x<=this->nrNodes; x++) {
        for(int y: la[x]) {
            if(this->degrees[y] == 0)
                out<<x<<" "<<y<<"\n";
        }
        setNodeDegree(x, getNodeDegree(x) + 1);
    }
}

/*
1 2 3 4 5 6
2 3 2 3 2 2
0 2 1 3 2 2
0 0 0 2 2 2
0 0 0 0 1 1
0 0 0 0 0 0

node = 5
1: 2, 3
2: 1, 3, 4
3: 1, 2
4: 2, 5, 6
5: 4, 6
6: 4, 5
*/