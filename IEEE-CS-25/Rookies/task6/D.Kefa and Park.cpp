#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> cats;
int n, m;
int validRestaurants = 0;

void dfs(int node, int parent, int consecutiveCats) {

    if (cats[node] == 1) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }

    if (consecutiveCats > m) {
        return;
    }

    bool isLeaf = true;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            isLeaf = false;
            dfs(neighbor, node, consecutiveCats);
        }
    }

    if (isLeaf) {
        validRestaurants++;
    }
}

int main() {
    cin >> n >> m;
    cats.resize(n + 1);
    graph.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << validRestaurants << endl;

    return 0;
}
