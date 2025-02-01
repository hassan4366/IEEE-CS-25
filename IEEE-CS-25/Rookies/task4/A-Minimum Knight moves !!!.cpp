#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
const vector<pair<int, int>> knightMoves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};
pair<int, int> chessToBoard(const string& pos) {
    int x = pos[0] - 'a';
    int y = pos[1] - '1';
    return {x, y};
}
int minKnightMoves(const string& start, const string& destination) {
    auto [starta, startb] = chessToBoard(start);
    auto [desta, destb] = chessToBoard(destination);
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({starta, startb});
    visited.insert({starta, startb});

    int moves = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            auto [a, b] = q.front();
            q.pop();
            if (a == desta && b == destb) {
                return moves;
            }
            for (const auto& move : knightMoves) {
                int newa = a + move.first;
                int newb = b + move.second;
                if (newa >= 0 && newa < 8 && newb >= 0 && newb < 8 && visited.find({newa, newb}) == visited.end()) {
                    visited.insert({newa, newb});
                    q.push({newa, newb});
                }
            }
        }

        moves++;
    }
    return -1;
}
int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; ++i) {
        string start, destination;
        getline(cin, start);
        destination = start.substr(3, 2);
        start = start.substr(0, 2);

        int result = minKnightMoves(start, destination);
        cout << result << endl;
    }

    return 0;
}
