#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(size_t size) {
    Init(size);
}

MatrixGraph::~MatrixGraph() {

}

void MatrixGraph::AddEdge(int from, int to) {
    graph[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return vertices;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> next;
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] != 0)
            next.push_back(i);
    }
    return next;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (int i = 0; i < vertices; i++) {
        if (graph[i][vertex] != 0)
            prev.push_back(i);
    }
    return prev;
}

MatrixGraph::MatrixGraph(const IGraph &other) {
    Init(other.VerticesCount());
    for (int i = 0; i < vertices; i++) {
        std::vector<int> temp(other.GetNextVertices(i));
        for (auto it : temp) {
            graph[i][it] = 1;
        }
    }
}

void MatrixGraph::Init(size_t size) {
    vertices = size;
    graph.resize(vertices);
    for (int i = 0; i < vertices; i++) {
        graph[i].resize(vertices);
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}
