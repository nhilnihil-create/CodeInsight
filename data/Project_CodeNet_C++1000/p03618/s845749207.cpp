#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll INF = 1e18;

int main() {
    string A;
    cin >> A;
    ll l = A.size(), n[26];
    rep(i, 26) n[i] = 0;
    rep(i, l) n[A[i] - 'a']++;
    ll ans = l * (l - 1) / 2 + 1;
    rep(i, 26) ans -= n[i] * (n[i] - 1) / 2;
    cout << ans << endl;
}