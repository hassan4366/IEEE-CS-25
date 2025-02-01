#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(k), b(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
        }

        while (q--) {
            int d;
            cin >> d;
            if (d == 0) {
                cout << "0 ";
                continue;
            }
            int idx = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
            if (idx == -1) {
                cout << "0 ";
                continue;
            }
            int a_prev = a[idx];
            int b_prev = b[idx];
            int a_next = a[idx + 1];
            int b_next = b[idx + 1];
            double speed = (double)(b_next - b_prev) / (a_next - a_prev);
            int time = b_prev + (d - a_prev) * speed;
            cout << time << " ";
        }
        cout << "\n";
    }
    return 0;

}
