#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
ll MOD = 1e9 + 7;

int main() {
    ll n; cin >> n;
    vector<ll> ac(n);
    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        ac[a]++;
    }
    ll s = n % 2 + 1;
    ll ans = 1;
    for(ll i = s; i < n; i+=2){
        if(ac[i] == 2){
            ans *= 2;
            ans %= MOD;
        }else{
            ans = 0;
            break;
        }
    }
    if(n % 2 != 0 && ac[0] != 1) ans = 0;
    cout << ans << endl;

}
