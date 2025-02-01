#include <iostream>
#include <vector>

using namespace std;

bool isLucky(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> luckyNumbers;
    for (int i = 1; i <= n; ++i) {
        if (isLucky(i)) {
            luckyNumbers.push_back(i);
        }
    }

    for (int lucky : luckyNumbers) {
        if (n % lucky == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
