#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const vector<pair<int, int>> directions = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
void dfs(int x, int y, vector<vector<char>>& map, vector<vector<bool>>& visited) {
    stack<pair<int, int>> s;
    s.push({x, y});

    while (!s.empty()) {
        auto [currX, currY] = s.top();
        s.pop();

        for (const auto& dir : directions) {
            int newX = currX + dir.first;
            int newY = currY + dir.second;
            if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size() &&
                map[newX][newY] == '.' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                s.push({newX, newY});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    int roomCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !visited[i][j]) {
                visited[i][j] = true;
                dfs(i, j, map, visited);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
