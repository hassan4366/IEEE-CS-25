#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string directions;
    cin >> directions;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    int min_collision_time = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (directions[i] == 'R' && directions[i + 1] == 'L') {
            int collision_time = (positions[i + 1] - positions[i]) / 2;
            if (min_collision_time == -1 || collision_time < min_collision_time) {
                min_collision_time = collision_time;
            }
        }
    }

    cout << min_collision_time << endl;
    return 0;
}
