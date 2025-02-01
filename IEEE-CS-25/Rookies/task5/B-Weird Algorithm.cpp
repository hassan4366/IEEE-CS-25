#include <iostream>
using namespace std;

int main() {
    long long X;
    cin >> X;
    while (X != 1) {
        cout << X << " ";
        if (X % 2 == 0) {
            X /= 2;
        } else {
            X = X * 3 + 1;
        }
    }
    cout << X << endl;
    return 0;
}
