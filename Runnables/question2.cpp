#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a structure to represent a weighted edge
struct Edge {
    int to;
    int weight;
};

// Define a function to perform Dijkstra's algorithm
vector<int> dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);

    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    // Create a graph (adjacency list representation) and populate it with edges and weights

    int n = 6; // Number of nodes in the graph
    vector<vector<Edge>> graph(n);

    // Populate the graph with edges and weights (example)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 2});
    graph[4].push_back({5, 5});

    int source = 0; // Source node

    vector<int> distance = dijkstra(graph, source);

    // Print the shortest distances from the source node to all other nodes
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from node " << source << " to node " << i << ": " << distance[i] << endl;
    }

    return 0;
}
