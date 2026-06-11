#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int start = 1;
    if (n % 2) start = 0;
    for (int i = start; i < n; i += 2) {
        if (a[i] != 2) {
            if(i == 0 && a[i] == 1) continue;
            cout << 0;
            return;
        }
    }
    long long ans = 1;
    long long md = 1e9 + 7;
    for (int i = 0; i < n/2; i++) {
        ans = (ans * 2) % md;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
