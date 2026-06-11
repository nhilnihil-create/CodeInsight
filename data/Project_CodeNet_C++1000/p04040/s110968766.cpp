#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int N = 1100000;
ll fact[N], ifact[N];

ll powmod(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void init(){
    fact[0] = ifact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (fact[i-1] * i) % mod;
        ifact[i] = powmod(fact[i], mod - 2);
    }
}

ll nCr(ll n, ll r){
    return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
    init();
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for(int i = b + 1; i <= w; i++){
        ans = (ans + nCr(h - a + i - 2, i - 1) * nCr(a - 1 + w - i, a - 1)) % mod;
    }
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}