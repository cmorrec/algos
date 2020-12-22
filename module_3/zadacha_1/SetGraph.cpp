#include "SetGraph.h"


SetGraph::SetGraph(size_t size) {
    vertices = size;
    graph.resize(vertices);
}

SetGraph::~SetGraph() = default;

void SetGraph::AddEdge(int from, int to) {
    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> next;
    for (auto it : graph[vertex]) {
        next.push_back(it);
    }
    return next;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (int i = 0; i < vertices; i++) {
        for (auto it : graph[i]) {
            if (it == vertex) prev.push_back(i);
        }
    }
    return prev;
}

SetGraph::SetGraph(const IGraph &other) {
    vertices = other.VerticesCount();

    graph.resize(vertices);
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> next(other.GetNextVertices(i));
        for (auto it : next) {
            graph[i].insert(it);
        }
    }
}