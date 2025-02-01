#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    int count = 0;
    for (int i = 0; i < n - 2; ++i) {
        int h = i + 2;
        while (h < n && points[h] - points[i] <= d) {
            ++h;
        }
        int k = h - i - 1;
        if (k >= 2) {
            count += (k * (k - 1)) / 2;
        }
    }

    cout << count << endl;

    return 0;
}
