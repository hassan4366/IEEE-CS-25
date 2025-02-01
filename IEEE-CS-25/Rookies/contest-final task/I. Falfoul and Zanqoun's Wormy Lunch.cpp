#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> prefixSum(n);


    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        prefixSum[i] = (i == 0 ? a[i] : prefixSum[i - 1] + a[i]);
    }

    int m;
    cin >> m;

    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }


    for (int i = 0; i < m; ++i) {
        int wormLabel = queries[i];

        int pileNumber = upper_bound(prefixSum.begin(), prefixSum.end(), wormLabel) - prefixSum.begin();
        cout << pileNumber + 1 << endl; // طباعة رقم الكومة (بدءًا من 1)
    }

    return 0;
}
