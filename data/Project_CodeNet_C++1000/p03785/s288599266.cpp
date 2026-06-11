#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c, k;
    cin >> n >> c >> k;

    vector<int> ts(n);
    for (int i = 0; i < n; i++) cin >> ts[i];
    sort(ts.begin(), ts.end());

    int ans = 1;
    int nax = ts[0] + k;
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (ts[i] <= nax && cur < c) {
            cur++;
            continue;
        }
        ans++;
        cur = 1;
        nax = ts[i] + k;
    }
    cout << ans << endl;
}
