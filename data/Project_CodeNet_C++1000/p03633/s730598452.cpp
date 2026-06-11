#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> t(n);
    for (ll i = 0;i < n;i++){
        cin >> t[i];
    }

    ll ans = t[0];

    for (ll i = 0; i < n; i++){
        ans = lcm(ans,t[i]);
    }

    cout << ans << endl;
}