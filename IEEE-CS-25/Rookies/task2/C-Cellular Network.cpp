#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int dist = INT_MAX;
        if (it != b.end()) {
            dist = abs(a[i] - *it);
        }
        if (it != b.begin()) {
            dist = min(dist, abs(a[i] - *(it - 1)));
        }
        r = max(r, dist);
    }
    cout << r << endl;

    return 0;
}
