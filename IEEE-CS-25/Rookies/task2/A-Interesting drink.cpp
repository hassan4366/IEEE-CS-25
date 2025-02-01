#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int q;
    cin >> q;
    while (q--) {
        int mi;
        cin >> mi;
        int count = upper_bound(prices.begin(), prices.end(), mi) - prices.begin();
        cout << count << "\n";
    }

    return 0;
}
