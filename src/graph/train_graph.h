
#ifndef TRAIN_GRAPH_H
#define TRAIN_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class TrainGraph {
private:
    int V;

    // Adjacency List
    vector<vector<pair<int, int>>> adj;

public:
    TrainGraph(int vertices);

    // Add railway route
    void addRoute(int u, int v, int distance);

    // Dijkstra's shortest path
    void dijkstra(int source);
};

#endif
