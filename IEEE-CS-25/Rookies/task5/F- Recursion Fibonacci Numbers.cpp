#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the position (n) in Fibonacci sequence: ";
    cin >> n;
    if (n < 0 || n > 30) {
        cout << "Enter a value between 0 and 30." << endl;
    } else {
        cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    }
    return 0;
}
