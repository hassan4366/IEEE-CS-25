#include <iostream>
using namespace std;

long long calculateLines(long long v, long long k) {
    long long total = 0;
    long long current = v;
    while (current > 0) {
        total += current;
        current /= k;
    }
    return total;
}
int main() {
    long long n, k;
    cin >> n >> k;

    long long left = 1, right = n, result = n;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (calculateLines(mid, k) >= n) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
