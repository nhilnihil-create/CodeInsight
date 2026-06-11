#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    if (abs(n-m)>1) {
        cout << 0;
        return 0;
    }
    vector<ll> facts(100001);
    facts[0] = 1;
    for (ll i=1; i<=100000; i++) facts[i] = facts[i-1]*i%MOD;
    ll res = facts[n]*facts[m];
    if (n==m) res*=2;
    res%=MOD;
    cout << res;
    return 0;
}