#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, d[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        d[u]++, d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] & 1) { cout << "NO" << endl; exit(0); }
    }
    cout << "YES" << endl;
    return 0;
}
