#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <experimental/optional>

typedef std::pair<std::string, int> Edge;

struct Vertex {
  std::string vertex;
  std::vector<Edge> edges;

  Vertex(std::string s) : vertex(s){};
};

class Graph {
private:
  std::vector<Vertex> graph;

public:
  unsigned long size() const;
  void addVertex(std::string);
  void addEdge(std::string, std::string, int);
  void removeEdge(std::string, std::string);
  void depthFirstSearch(const std::function<void(std::string)> &, std::experimental::optional<std::string>);
  void print() const;
};

unsigned long Graph::size() const {
  auto i = this->graph.size();
  return this->graph.size();
};

void Graph::addVertex(std::string vertex) {
  this->graph.push_back(Vertex(vertex));
}

void Graph::addEdge(std::string v1, std::string v2, int weight) {
  if (v1 == v2)
    return;

  int indexV1 = -1;
  int indexV2 = -1;
  for (int i = 0; i < this->graph.size(); i++) {
    if (v1 == this->graph[i].vertex) {
      indexV1 = i;
    } else if (v2 == this->graph[i].vertex) {
      indexV2 = i;
    }
  };
  if (indexV1 < 0 || indexV2 < 0)
    return;

  // conect
  bool alreadyConnected = false;
  for (auto edge : this->graph[indexV1].edges) {
    if (edge.first == v2) {
      alreadyConnected = true;
    }
  };
  if (alreadyConnected)
    return;

  Edge newEdge = std::make_pair(v2, weight);
  this->graph[indexV1].edges.emplace_back(newEdge);

  newEdge = std::make_pair(v1, weight);
  this->graph[indexV2].edges.emplace_back(newEdge);
}

void Graph::removeEdge(std::string v1, std::string v2) {
  if (v1 == v2)
    return;

  int indexOfV1Edge = -1;
  int indexOfV2Edge = -1;
  int indexV1 = -1;
  int indexV2 = -1;
  for (int i = 0; i < this->graph.size(); i++) {
    if (v1 == this->graph[i].vertex) {
      indexV1 = i;
    } else if (v2 == this->graph[i].vertex) {
      indexV2 = i;
    }
  };
  if (indexV1 < 0 || indexV2 < 0)
    return;

  // finding v1 edge index
  for (int i = 0; i < this->graph[indexV1].edges.size(); i++) {
    if (this->graph[indexV1].edges[i].first == v2) {
      indexOfV1Edge = i;
    }
  }

  // finding v2 edge index
  for (int i = 0; i < this->graph[indexV2].edges.size(); i++) {
    if (this->graph[indexV2].edges[i].first == v1) {
      indexOfV2Edge = i;
    }
  }

  if (indexOfV1Edge < 0 || indexOfV2Edge < 0)
    return;

  // removing
  this->graph[indexV1].edges.erase(this->graph[indexV1].edges.begin() +
                                   indexOfV1Edge);
  this->graph[indexV2].edges.erase(this->graph[indexV2].edges.begin() +
                                   indexOfV2Edge);
}

void Graph::depthFirstSearch(const std::function<void(std::string)> &callback, std::experimental::optional<std::string> v) {
    static std::unordered_map<std::string, bool> visited;
    std::string vertex;
    if(v == std::experimental::nullopt) {
        vertex = this->graph[0].vertex; 
    } else {
        vertex = v.value();
    }

    if(visited[vertex]) return;
    visited[vertex] = true;
    callback(vertex);
    int indexOfVertex = -1;
    for(int i = 0; i < this->size(); i++) {
        if(this->graph[i].vertex == vertex) {
            indexOfVertex = i;
        }
    };
    if(indexOfVertex < 0) return;
    for(auto ve : this->graph[indexOfVertex].edges) {
        this->depthFirstSearch(callback, ve.first);
    }
}


void Graph::print() const {
    for(auto i : this->graph) {
        std::cout << i.vertex << std::endl;
        std::cout << '\t';
        for(auto j : i.edges) {
            std::cout << j.first << " " << j.second;
            std::cout << "  ";
        }
        std::cout << '\n';
    }
}

void print(std::string s) { std::cout << s << std::endl;}
