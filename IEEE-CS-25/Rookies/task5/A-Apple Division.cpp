#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    long long total_weight = 0;
    for (int weight : weights) {
        total_weight += weight;
    }

    long long min_diff = LLONG_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1_weight = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1_weight += weights[i];
            }
        }

        long long group2_weight = total_weight - group1_weight;
        min_diff = min(min_diff, abs(group1_weight - group2_weight));
    }
    cout << min_diff << endl;
    return 0;
}
