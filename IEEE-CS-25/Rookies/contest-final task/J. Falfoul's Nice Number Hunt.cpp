#include <iostream>
#include <vector>

using namespace std;

vector<int> generateNiceNumbers() {
    vector<int> niceNumbers;
    for (int i = 0; i < 100; ++i) {
        string str = to_string(i);
        bool isNice = true;
        for (char c : str) {
            if (c != '6' && c != '9') {
                isNice = false;
                break;
            }
        }
        if (isNice) {
            niceNumbers.push_back(i);
        }
    }
    return niceNumbers;
}

int main() {
    int t;
    cin >> t;

    vector<int> niceNumbers = generateNiceNumbers();

    while (t--) {
        int n;
        cin >> n;


        int result = -1;
        for (int nice : niceNumbers) {
            if (nice >= n) {
                result = nice;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}
