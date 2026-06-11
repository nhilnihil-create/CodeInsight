#include <bits/stdc++.h>

using namespace std;
signed main () {
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int x, y;cin >> x >> y;v.push_back(x); v.push_back(y);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i += 2) {
        ans += v[i];
    }
    cout << ans << '\n';
}
