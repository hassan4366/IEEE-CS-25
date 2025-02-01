#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int a = 0, b = 0;
    int left = 0, right = n - 1;
    int timeAlice = 0, timeBob = 0;
    while (left <= right) {
        if (timeAlice <= timeBob) {
            timeAlice += t[left];
            left++;
            a++;
        } else {
            timeBob += t[right];
            right--;
            b++;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
