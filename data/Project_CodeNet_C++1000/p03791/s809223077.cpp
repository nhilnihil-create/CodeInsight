#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int N, x, j = 0;
    cin >> N;
    ll ans = 1;
    rep(i, N) {
        cin >> x;
        if (x < (i - j) * 2 + 1) {
            ans = (ans * (i - j + 1)) % MOD;
            //cout << i << j << ans << endl;
            j++;
        }
    }
    for (int i = 1; i <= N - j; ++i) {
        ans = (ans * i) % MOD;
    }
    cout << ans << endl;
}