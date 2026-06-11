#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    for (auto a : g[0]) {
        for (auto b : g[a]) {
            if (n == b + 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

