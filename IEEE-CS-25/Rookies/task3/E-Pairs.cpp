#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int pairs(int k, const vector<int>& arr) {
    unordered_set<int> elements;
    int count = 0;
    for (int num : arr) {
        elements.insert(num);
    }
    for (int num : arr) {
        if (elements.find(num + k) != elements.end()) {
            count++;
        }
    }
    return count;
}
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << pairs(k, arr) << endl;
    return 0;
}
