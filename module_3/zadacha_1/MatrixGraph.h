#ifndef ZADACHA_1_MATRIXGRAPH_H
#define ZADACHA_1_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph {
private:
    size_t vertices;
    std::vector<std::vector<int>> graph;

    void Init(size_t);

public:
    explicit MatrixGraph(size_t size);
    explicit MatrixGraph(const IGraph &other);
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //ZADACHA_1_MATRIXGRAPH_H
