#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000000000+7)
int main() {
    int n, m; cin >> n >> m;
    if (abs(n-m) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    Int np = n, mp = m;
    if (n > m) {
        np = m;
        mp = n;
    }
    Int npp = np, mpp;
    np--;
    while (np >= 1) {
        npp = (Int)(((npp%MOD) * (np%MOD)) %MOD);
        np--;
    }
    //cout << npp << endl;
    if (n == m) {
        cout << (Int)(((Int)((npp % MOD) * (npp % MOD)) * 2) % MOD) << endl;
    }
    else {
        mpp = (Int)(((Int)(npp % MOD) * (mp % MOD)) % MOD);
        cout << (Int)((Int)(npp % MOD) * (mpp % MOD) % MOD) << endl;
    }
}
