#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<string> board(N);
vector<bool> column(N, false), diag1(2 * N, false), diag2(2 * N, false);
int solutions = 0;
void solve(int row) {
    if (row == N) {
        // All queens are placed
        solutions++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (board[row][col] == '*' || column[col] || diag1[row - col + N] || diag2[row + col]){
            continue;
        }
        column[col] = diag1[row - col + N] = diag2[row + col] = true;
        solve(row + 1);
        column[col] = diag1[row - col + N] = diag2[row + col] = false;
    }
}

int main() {
    // Input the chessboard
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // Start solving
    solve(0);

    // Output the result
    cout << solutions << endl;

    return 0;
}
