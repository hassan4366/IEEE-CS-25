#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }


    int max_pos = 0;
    for (int i = 1; i < n; ++i) {
        if (heights[i] > heights[max_pos]) {
            max_pos = i;
        }
    }


    int min_pos = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (heights[i] < heights[min_pos]) {
            min_pos = i;
        }
    }

    int swaps = max_pos + (n - 1 - min_pos);

    if (max_pos > min_pos) {
        --swaps;
    }

    cout << swaps << endl;

    return 0;


}
