#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
ll MOD = 1e9 + 7;

int main() {
    ll n; cin >> n;
    map<ll, ll> m1;
    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        m1[a]++;
    }
    map<ll, ll> m2;
    ll j = n - 1;
    for(ll i = 0; i < n; i++){
        ll t = abs(j - i);
        m2[t]++;
        j--;
    }
    bool flag = true;
    for(ll i = 0; i < n; i++){
        if(m1[i] != m2[i]){
            flag = false;
            break;
        }
    }
    ll ans = 1;
    for(int i = 1; i <= n / 2; i++){
        ans *= 2;
        ans %= MOD;
    }
    if(flag) cout << ans << endl;
    else cout << 0 << endl;
}
