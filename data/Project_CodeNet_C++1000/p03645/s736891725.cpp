#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    unordered_map<int, unordered_map<int, bool>> possible;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        possible[a][b] = possible[b][a] = true;
    }

    for (int i = 2; i < n; ++i) {
        if (possible[1][i] && possible[i][n]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

