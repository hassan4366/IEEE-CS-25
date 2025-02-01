#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string input;
    cin >> input;
    set<string> permutations;
    sort(input.begin(), input.end());
    do {
        permutations.insert(input);
    } while (next_permutation(input.begin(), input.end()));
    cout << permutations.size() << endl;
    for (const auto& perm : permutations) {
        cout << perm << endl;
    }
    return 0;
}
