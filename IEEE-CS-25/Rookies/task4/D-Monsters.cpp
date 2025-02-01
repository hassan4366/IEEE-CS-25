#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int dx[4] = {1, 0, -1, 0}; // Down, Right, Up, Left
const int dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};

bool is_within_bounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool bfs(const vector<string>& labyrinth, pair<int, int> start, const vector<pair<int, int>>& monsters, int n, int m, string& path) {
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    map<pair<int, int>, pair<int, int>> parent;

    q.push(start);
    visited.insert(start);
    parent[start] = {-1, -1}; // Start has no parent

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // Check if we are at the boundary
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            // Reconstruct the path
            path.clear();
            while (current != make_pair(-1, -1)) {
                auto prev = parent[current];
                if (prev != make_pair(-1, -1)) {
                    for (int d = 0; d < 4; ++d) {
                        if (current.first == prev.first + dx[d] && current.second == prev.second + dy[d]) {
                            path += dir[d];
                            break;
                        }
                    }
                }
                current = prev;
            }
            reverse(path.begin(), path.end());
            return true;
        }

        // Explore all possible moves
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (is_within_bounds(nx, ny, n, m) && labyrinth[nx][ny] == '.' && visited.find({nx, ny}) == visited.end()) {
                // Check if this position is safe from monsters
                bool safe = true;
                for (const auto& monster : monsters) {
                    int mx = monster.first;
                    int my = monster.second;
                    for (int md = 0; md < 4; ++md) {
                        int mmx = mx + dx[md];
                        int mmy = my + dy[md];
                        if (is_within_bounds(mmx, mmy, n, m) && mmx == nx && mmy == ny) {
                            safe = false;
                            break;
                        }
                    }
                    if (!safe) break;
                }

                if (safe) {
                    visited.insert({nx, ny});
                    q.push({nx, ny});
                    parent[{nx, ny}] = {x, y};
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> labyrinth(n);
    pair<int, int> start;
    vector<pair<int, int>> monsters;

    for (int i = 0; i < n; ++i) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; ++j) {
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    string path;
    if (bfs(labyrinth, start, monsters, n, m, path)) {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
