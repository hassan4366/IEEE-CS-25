#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long countPairs(vector<int>& a, int l, int r) {
    sort(a.begin(), a.end());
    long long count = 0;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        int lower = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
        int upper = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
        count += (upper - lower);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << countPairs(a, l, r) << "\n";
    }

    return 0;
}

