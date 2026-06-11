#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>());
    rep(i, 0, m) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        edge[from].push_back(to);
    }
    for (int fst : edge[0]) {
        for (int sec : edge[fst]) {
            if (sec == n - 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
