#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

int main() {
    int n; cin >> n;
    int d[n];
    for (int i = 0; i < n; i++) d[i] = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        d[a]++;
    }
    bool ok = true;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && d[i] != 0) ok = false;
            if (i % 2 == 1 && d[i] != 2) ok = false;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i == 0 && d[i] != 1) ok = false;
            if (i != 0 && i % 2 == 0 && d[i] != 2) ok = false;
            if (i % 2 == 1 && d[i] != 0) ok = false; 
        }
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            ans *= 2;
            ans %= mod;
        }
    } else {
        for (int i = 1; i <= (n - 1) / 2; i++) {
            ans *= 2;
            ans %= mod;
        }
    }
    cout << ans << endl;
}