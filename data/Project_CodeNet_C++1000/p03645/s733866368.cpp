#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int s = v[1].size();
    for (int i = 0; i < s; i++) {
        int x = v[1][i];
        sort (BE(v[x]));
        if (v[x].back() == n) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
