#include "headers/graph.hpp"
#include <iostream>
#include <fstream>

Graph& readGraph(std::ifstream& fin) {
    int nrNodes, dx;
    fin>>nrNodes;
    Graph* myGraph = new Graph(nrNodes);
    myGraph->initDegreesVector(nrNodes);
    for(int x=1; x<=nrNodes; x++) {
        fin>>dx;
        myGraph->setNodeDegree(x, dx);
    }
    return *myGraph;
}

int main(int argc, char* argv[]) {
    std::ifstream graph("var/date.in");
    Graph myGraph = readGraph(graph);
    std::cout<<"Lista gradelor nodurilor grafului este: ";
    myGraph.showDegrees();
    if(myGraph.sumOfDegrees() % 2 == 0) {
        std::cout<<"Construiesc graful... \n";
        myGraph.constructGraph();
        std::ofstream result("var/date.out");
        myGraph.printGraph(result);
        std::cout<<"Graful rezultat este fisierul var/date.out\n";
    } else
        std::cout<<"Nu poate fi construit un graph cu aceasta lista a gradelor!";
    return 0;
}