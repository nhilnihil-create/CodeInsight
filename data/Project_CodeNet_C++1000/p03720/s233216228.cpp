#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int from, to;
    cin >> n >> m;

    vector<int> cities(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        cities.at(from - 1)++;
        cities.at(to - 1)++;
    }

    for (int i = 0; i < n; i++) {
        cout << cities.at(i) << endl;
    }

    return 0;
}
