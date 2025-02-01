#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int totalScore = 0;
    int consecutiveWins = 0;

    for (int i = 0; i < N; ++i) {
        int result;
        cin >> result;

        if (result == 1) {
            totalScore += 1;
            consecutiveWins += 1;

            if (consecutiveWins >= 3) {
                totalScore += 1;
            }
        } else {
            totalScore -= 1;
            consecutiveWins = 0;
        }
    }

    cout << totalScore << endl;

    return 0;
}
