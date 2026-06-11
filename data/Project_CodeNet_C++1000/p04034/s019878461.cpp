#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int cnt[n], ans = 0;
    bool red[n] = {};

    red[0] = 1;
    for (int &x : cnt)
        x = 1;

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        red[y] = max(red[y], red[x]);
        cnt[y]++;
        cnt[x]--;
        red[x] = min(red[x], (bool)cnt[x]);
    }

    for (bool x : red)
        if (x)
            ans++;
    cout << ans << '\n';
}