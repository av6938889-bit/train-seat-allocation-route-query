
#include "train_graph.h"

// Constructor
TrainGraph::TrainGraph(int vertices) {
    V = vertices;
    adj.resize(V);
}

// Add undirected weighted route
void TrainGraph::addRoute(int u, int v, int distance) {
    if (u < 0 || v < 0 || u >= V || v >= V || distance < 0) {
        cout << "Invalid route!\n";
        return;
    }

    adj[u].push_back({v, distance});
    adj[v].push_back({u, distance});
}

// Dijkstra's Algorithm
void TrainGraph::dijkstra(int source) {
    if (source < 0 || source >= V) {
        cout << "Invalid source station!\n";
        return;
    }

    vector<int> dist(V, INT_MAX);

    // Min-Heap: {distance, station}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] <= INT_MAX - weight &&
                dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Distances from Station "
         << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Station " << i << ": ";

        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << " km\n";
    }
}
