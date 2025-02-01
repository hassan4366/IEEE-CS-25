#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int cost;
};

vector<vector<Edge>> graph;
vector<bool> visited;
int maxCost = 0;

void dfs(int node, int currentCost) {
    visited[node] = true;

    // Update the maximum cost
    maxCost = max(maxCost, currentCost);

    // Traverse all connected friends
    for (const Edge& edge : graph[node]) {
        if (!visited[edge.to]) {
            dfs(edge.to, currentCost + edge.cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    // Start DFS from node 0 with initial cost 0
    dfs(0, 0);

    cout << maxCost << endl;

    return 0;
}
