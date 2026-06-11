#include <bits/stdc++.h>
using namespace std;


void solve () {
   long long n, m;
    cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0;
        return;
    }
    long long f = 1;
    long long md = 1e9 + 7;
    for (int i = 2; i <= min (n, m); i++) {
        f = f * i % md;
    }
    long long x = 1;
    long long mx = max(n, m);
    if (n == m){
        x = 2;
        mx = 1;
    }
    f = f * f % md;
    cout << f * mx * x % md;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
