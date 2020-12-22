#ifndef ZADACHA_1_ARCGRAPH_H
#define ZADACHA_1_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph {
private:
    size_t vertices;
    std::vector<std::pair<int, int>> graph;

public:
    explicit ArcGraph(size_t size);
    explicit ArcGraph(const IGraph &other);
    ~ArcGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //ZADACHA_1_ARCGRAPH_H
