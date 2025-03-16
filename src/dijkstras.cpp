#include "dijkstras.h"
#include <iostream>
#include <queue>

// bool operator>(const Edge& a, const Edge& b) {
//     return a.weight > b.weight;
// }

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.size();
    // the graph itself is the adjacency list 
    // source is the vertex 
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous.assign(numVertices, -1);
    std::priority_queue<pair<int,int>, vector<pair<int,int> >, std::greater<pair<int, int> > > minHeap;
    minHeap.push({source, 0});
    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        minHeap.pop();

        if (visited[u]) { continue; }

        visited[u] = true;

        for (const auto& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    // vector<int> palce;
    // return palce;
    
}

void print_path(const vector<int>& v, int total) {
    for (int i = 0; i < total; ++i) {
        std::cout << v[i] << " ";
    }
}