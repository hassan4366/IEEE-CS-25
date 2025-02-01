#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> skills(n);

    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }
    sort(skills.begin(), skills.end());

    int start = 0, max_team_size = 0;
    for (int end = 0; end < n; ++end) {
        while (skills[end] - skills[start] > 5) {
            ++start;
        }
        max_team_size = max(max_team_size, end - start + 1);
    }

    cout << max_team_size << endl;
    return 0;
}
