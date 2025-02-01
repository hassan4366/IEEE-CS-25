#include <bits/stdc++.h>

using namespace std;

void findSubsegment(int n, vector<int>& a) {

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) isIncreasing = false;
        if (a[i] > a[i-1]) isDecreasing = false;
    }

    if (isIncreasing || isDecreasing) {
        cout << -1 << endl;
        return;
    }

    int l = 0, r = n - 1;
    while (l < r && a[l] < a[l+1]) l++;
    while (l < r && a[r] > a[r-1]) r--;

    cout << l + 1 << " " << r + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        findSubsegment(n, a);
    }
    return 0;
}

