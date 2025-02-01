#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int bfs(int startX, int startY) {
    int volume = 0;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        volume += grid[x][y];

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                grid[newX][newY] > 0 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    return volume;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.assign(n, vector<int>(m));
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int maxVolume = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxVolume = max(maxVolume, bfs(i, j));
                }
            }
        }

        cout << maxVolume << endl;
    }
    return 0;
}
