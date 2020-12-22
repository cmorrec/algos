#include "ListGraph.h"

ListGraph::ListGraph(size_t verticesCount) {
    graph.resize(verticesCount);
}

ListGraph::ListGraph(const IGraph& other) {
    auto verticesCount = other.VerticesCount();

    graph.resize(verticesCount);
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> next(other.GetNextVertices(i));
        for (auto it : next) {
            if (i < it)
                graph[i].push_back(it);
        }
    }
}


ListGraph::~ListGraph() {
}

void ListGraph::AddEdge(int from, int to) {
    graph[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    result.resize(graph[vertex].size());
    std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (auto child : graph[i]) {
            if (child == vertex) {
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}
