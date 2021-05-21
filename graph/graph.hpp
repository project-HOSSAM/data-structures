#include <unordered_map>
#include <functional>

template <typename T> struct Edge {
  T vertex;
  int weight;
  Edge *edge;
  inline Edge(T vertex, int weight = 1) {
    this->vertex = vertex;
    this->weight = weight;
    this->edge = nullptr;
  }
};


template <typename T> using AdjacencyList = std::unordered_map<T, Edge<T>*>;

template <typename T> class Graph {
private:
  AdjacencyList<T> adj;

private:
  void addEdgeHelper(T,T, int);  
  void removeEdgeHelper(T, T);
  void forEachEdge(T, std::function<void(Edge<T>)>);

public:
  void addVertex(T);
  void addEdge(T, T, int);
  void removeEdge(T,T);
  void removeVertex(T);
  bool exists(T);

  void depthFirstSeach(const std::function<void(T)>);	
  void breadthFirstSearch(const std::function<void(T)>);
};
