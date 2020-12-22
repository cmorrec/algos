#ifndef ZADACHA_1_LISTGRAPH_H
#define ZADACHA_1_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {
private:
    std::vector <std::vector<int> > graph;

public:
    explicit ListGraph(size_t verticesCount);

    explicit ListGraph(const IGraph&);

    ~ListGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const  override;

    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //ZADACHA_1_LISTGRAPH_H
