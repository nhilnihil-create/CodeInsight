#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii ;
const int mod = 1e9 + 7;

ll binPow(ll x, ll y, ll md = mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1){
            res = (res * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve(){
   ll n;
   cin >> n;
   vector<ll> t(n, 0);
   vector<ll> a(n, 0);
   for(ll i = 0; i < n; ++i){
       cin >> t[i] >> a[i];
   }
   for(ll i = 1; i < n; ++i){
       ll k = max((t[i - 1] + t[i] - 1) / t[i], (a[i - 1] + a[i] - 1) / a[i]);
       t[i] *= k;
       a[i] *= k;
   }
   cout << t[n - 1] + a[n - 1] << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

