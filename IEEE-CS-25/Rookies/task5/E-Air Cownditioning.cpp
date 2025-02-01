#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cooling;
};

struct AirConditioner {
    int start, end, power, cost;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cooling;
    }

    vector<AirConditioner> conditioners(M);
    for (int i = 0; i < M; i++) {
        cin >> conditioners[i].start >> conditioners[i].end >> conditioners[i].power >> conditioners[i].cost;
    }
    int minCost = INT_MAX;
    for (int mask = 0; mask < (1 << M); mask++) {
        vector<int> cooling(101, 0);
        int cost = 0;
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                cost += conditioners[i].cost;
                for (int j = conditioners[i].start; j <= conditioners[i].end; j++) {
                    cooling[j] += conditioners[i].power;
                }
            }
        }
        bool valid = true;
        for (const auto& cow : cows) {
            for (int j = cow.start; j <= cow.end; j++) {
                if (cooling[j] < cow.cooling) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) {
            minCost = min(minCost, cost);
        }
    }

    cout << minCost << endl;

    return 0;
}
