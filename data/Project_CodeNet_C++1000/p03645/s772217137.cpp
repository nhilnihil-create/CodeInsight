
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> visited(n + 1, 0), v1(1, 1), v2;
    visited[1] = 1;
    for (int i = 0; i < 2; i++) {
        v2.clear();
        for (auto node : v1) {
            for (auto next : v[node]) {
                if (i == 1 && next == n) {
                    cout << "POSSIBLE" << endl;
                    return 0;
                }
                if (visited[next] == 0) {
                    visited[next] = 1;
                    v2.push_back(next);
                }
            }
        }
        v1 = v2;
    }
    cout << "IMPOSSIBLE" << endl;
}
