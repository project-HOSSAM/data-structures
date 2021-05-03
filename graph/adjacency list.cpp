#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


struct Vertex {
    std::string vertex;
    int weight;
    Vertex(std::string v, int w){
        this->vertex = v;
        this->weight = w;
    }
};

class Graph {
private:
    std::unordered_map<std::string,std::vector<Vertex>> graph;
public:
    void addVertex(std::string);
    void addEdge(std::string, std::string, int);
    void remove(std::string, std::string);
};

void Graph::addVertex(std::string newVertex) {
    this->graph[newVertex] = std::vector<Vertex>{};
};

void Graph::addEdge(std::string v1, std::string v2, int weight) {
    for(auto edges : this->graph[v1]) {
        if(edges.vertex == v2) {
            return;
        }
    };
    this->graph[v1].push_back(Vertex(v2,weight));
    this->graph[v2].push_back(Vertex(v1,weight));

};
