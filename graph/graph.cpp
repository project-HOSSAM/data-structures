#include <unordered_map>
#include <stack>
#include <queue>
#include "./graph.hpp"

template<typename T> void Graph<T>::forEachEdge(T vertex, std::function<void(Edge<T>)> callback) {
	Edge<T> *currentEdge = this->adj[vertex];
	while(currentEdge) {
		callback(currentEdge);
		currentEdge = currentEdge->edge;
	}
} 

template <typename T> void Graph<T>::addVertex(T vertex) {
  this->adj[vertex] = nullptr;
}

template <typename T> void Graph<T>::addEdgeHelper(T vertex1, T vertex2, int weight) {
  auto newEdge = new Edge<T>(vertex2, weight);
  if (this->adj[vertex1] == nullptr) {
    this->adj[vertex1] = newEdge;
  } else {
    Edge<T> *currentEdge = this->adj[vertex1];
    while (currentEdge->edge) {
      currentEdge = currentEdge->edge;
    }
    currentEdge->edge = newEdge;
  }
}


template <typename T> void Graph<T>::removeEdgeHelper(T vertex1, T vertex2) {
	Edge<T> *currentEdge = this->adj[vertex1];
	if(currentEdge->vertex == vertex2) {
		Edge<T> *temp = currentEdge->edge;
		delete currentEdge;
		this->adj[vertex1] = temp; 
	} else {
		Edge<T> *pre = nullptr;
		while(currentEdge) {
			if(currentEdge->vertex == vertex2) {
				pre->edge = currentEdge->edge;
				delete currentEdge;
			} else {
				pre = currentEdge;
				currentEdge = currentEdge->edge;
			}
		}
	}
}


template <typename T> void Graph<T>::addEdge(T vertex1, T vertex2, int weight) {
  this->addEdgeHelper(vertex1,vertex2, weight);
  this->addEdgeHelper(vertex2, vertex1, weight);
}

template <typename T> void Graph<T>::removeEdge(T vertex1, T vertex2) {
  this->removeEdgeHelper(vertex1, vertex2);
  this->removeEdgeHelper(vertex2, vertex1);
}


template <typename T> bool Graph<T>::exists(T vertex) {
	// TODO : improve it from O(n) to O(1)

	for(auto& v : this->adj) {
		if(v.first == vertex) {
			return true;
		};
	};
	return false;
}


template<typename T> void Graph<T>::depthFirstSeach(const std::function<void(T)> callback) {
	std::unordered_map<T, bool> visited;
	std::stack<T> stack;
	auto firstVertex = this->adj.begin()->first;
	stack.push(firstVertex);

	while(!stack.empty()) {
		T v = stack.top();
		stack.pop();

		if(!visited[v]) {
			visited[v] = true;
            Edge<T> *edge = this->adj[v];
            while(edge) {
                stack.push(edge->vertex);
                edge = edge->edge;
            }
		}
	}

}

template<typename T> void Graph<T>::breadthFirstSearch(const std::function<void(T)> callback) {
    std::unordered_map<T, bool> visited;
    std::queue<T> queue;
    T firstVertex = this->adj.begin()->first;
    visited[firstVertex] = true;
    queue.push(firstVertex);
    while(!queue.empty()) {
        T v = queue.front();
        queue.pop();
        Edge<T> *edge = this->adj[v];
        while(edge) {
            if(!visited[edge->vertex]) {
                visited[edge->vertex] = true; 
                callback(edge->vertex);
                queue.push(edge->vertex);
            }
            edge = edge->edge;
        }
    }
}






