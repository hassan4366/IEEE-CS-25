#include <bits/stdc++.h>

using namespace std;

int countGoodSubsegments(int n, int m, int k, vector<int>& a, vector<int>& b) {
    unordered_map<int, int> freqB;
    for (int num : b) {
        freqB[num]++;
    }

    int goodCount = 0;
    unordered_map<int, int> freqWindow;
    int matchCount = 0;

    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            int leftElement = a[i - m];
            if (freqB.find(leftElement) != freqB.end()) {
                if (freqWindow[leftElement] <= freqB[leftElement]) {
                    matchCount--;
                }
            }
            freqWindow[leftElement]--;
        }

        int rightElement = a[i];
        if (freqB.find(rightElement) != freqB.end()) {
            if (freqWindow[rightElement] < freqB[rightElement]) {
                matchCount++;
            }
        }
        freqWindow[rightElement]++;

        if (i >= m - 1 && matchCount >= k) {
            goodCount++;
        }
    }

    return goodCount;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        cout << countGoodSubsegments(n, m, k, a, b) << endl;
    }
    return 0;
}
