#include <bits/stdc++.h>


using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> snowDrifts(n);
    for (int i = 0; i < n; ++i) {
        cin >> snowDrifts[i].first >> snowDrifts[i].second;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (snowDrifts[i].first == snowDrifts[j].first || snowDrifts[i].second == snowDrifts[j].second) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << (components - 1) << endl;

    return 0;
}
