#include "ArcGraph.h"


ArcGraph::ArcGraph(size_t size) {
    vertices = size;
    graph.reserve(vertices);
}

ArcGraph::~ArcGraph() = default;

void ArcGraph::AddEdge(int from, int to) {
    graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertices;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> next;
    for (auto it : graph) {
        if (it.first == vertex) {
            next.push_back(it.second);
        }
    }
    return next;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (auto it : graph) {
        if (it.second == vertex) {
            prev.push_back(it.first);
        }
    }
    return prev;
}

ArcGraph::ArcGraph(const IGraph &other) {
    vertices = other.VerticesCount();
    graph.reserve(vertices);
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> next(other.GetNextVertices(i));
        for (auto it : next) {
            if (i < it) {
                graph.emplace_back(i, it);
            }
        }
    }
}