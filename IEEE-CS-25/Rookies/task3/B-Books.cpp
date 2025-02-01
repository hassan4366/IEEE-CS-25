#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_books = 0, current_books = 0, current_time = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        current_time += a[end];
        current_books++;

        while (current_time > h) {
            current_time -= a[start];
            current_books--;
            start++;
        }

        max_books = max(max_books, current_books);
    }

    cout << max_books << endl;
    return 0;
}
