#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    ll n, k; cin >> n >> k;
    ll res = k;
    rep(i, n-1) res *= k-1;
    cout << res << endl;
}