#ifndef ZADACHA_1_SETGRAPH_H
#define ZADACHA_1_SETGRAPH_H

#include "IGraph.h"
#include <set>

class SetGraph : public IGraph {
private:
    size_t vertices;
    std::vector<std::set<int>> graph;

public:
    explicit SetGraph(size_t size);
    explicit SetGraph(const IGraph &other);
    ~SetGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

};

#endif //ZADACHA_1_SETGRAPH_H
