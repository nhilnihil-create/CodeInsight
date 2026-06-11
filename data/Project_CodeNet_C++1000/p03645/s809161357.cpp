#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool ok = false;
    for (auto k : v[0]) {
        if (k == n - 1) ok = true;
        for (auto l : v[k])
            if (l == n - 1) ok = true;
    }

    if (ok)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
