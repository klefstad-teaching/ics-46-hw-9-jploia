#include "dijkstras.h"
#include <iostream>
#include <queue>
#include <algorithm>

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
        int u = minHeap.top().second;
        int u_weight = minHeap.top().first;
        minHeap.pop();

        if (visited[u]) { continue; }

        visited[u] = true;

        for (const auto& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (distances[v] > distances[u_weight] + weight) {
                distances[v] = distances[u_weight] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> reversed;
    while (destination != -1) {
        reversed.push_back(destination);
        destination = previous[destination];
    }
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

void print_path(const vector<int>& v, int total) {
    for (const auto& val : v) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    std::cout << "Total cost is " << total << '\n';
}