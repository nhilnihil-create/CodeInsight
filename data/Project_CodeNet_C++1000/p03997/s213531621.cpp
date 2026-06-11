#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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
   int a, b, h;
   cin >> a >> b >> h;
   cout << ((a + b) * h) / 2 << "\n";
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
