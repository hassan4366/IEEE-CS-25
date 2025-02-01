#include <bits/stdc++.h>

using namespace std;

long long countValidVacations(int n, int k, int q, vector<int>& a) {
    long long result = 0;
    int start = 0;
    while (start < n) {
        if (a[start] > q) {
            start++;
            continue;
        }
        int end = start;
        while (end < n && a[end] <= q) {
            end++;
        }
        int length = end - start;
        if (length >= k) {
            result += (long long)(length - k + 1) * (length - k + 2) / 2;
        }
        start = end;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << countValidVacations(n, k, q, a) << '\n';
    }
    return 0;
}
