#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, m;
    cin >> n >> m;
    vector < int > cnt(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[a];
        ++cnt[b];
    }
    bool works = 1;
    for (int i = 0; i <= n; ++i) 
        works = works & !(cnt[i] & 1);
    if (works)
        cout << "YES\n";
    else
        cout << "NO\n";
}
