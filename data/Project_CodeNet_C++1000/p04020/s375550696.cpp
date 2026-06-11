#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vt(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> vt[i];
        if (vt[i] && i && vt[i - 1])
            vt[i - 1]--, vt[i]--, ans++;
        ans += vt[i] / 2;
        vt[i] = vt[i] % 2;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}
