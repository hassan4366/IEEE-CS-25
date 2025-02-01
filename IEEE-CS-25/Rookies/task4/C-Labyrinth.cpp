#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
const int MAXN = 1000;
const char WALL = '#';
const char FLOOR = '.';
const char START = 'A';
const char END = 'B';

int n, m;
char labyrinth[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
char direction[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dirChar[] = {'D', 'U', 'R', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != WALL && !visited[x][y];
}

int main() {
    cin >> n >> m;
    pair<int, int> start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == START) {
                start = {i, j};
            } else if (labyrinth[i][j] == END) {
                end = {i, j};
            }
        }
    }

    if (start == make_pair(-1, -1) || end == make_pair(-1, -1)) {
        cout << "NO" << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    parent[start.first][start.second] = {-1, -1};

    bool found = false;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (current == end) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                parent[newX][newY] = current;
                direction[newX][newY] = dirChar[i];
                q.push({newX, newY});
            }
        }
    }

    if (found) {
        cout << "YES" << endl;
        string path;
        pair<int, int> step = end;

        while (step != make_pair(-1, -1)) {
            if (parent[step.first][step.second] != make_pair(-1, -1)) {
                path += direction[step.first][step.second];
            }
            step = parent[step.first][step.second];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
