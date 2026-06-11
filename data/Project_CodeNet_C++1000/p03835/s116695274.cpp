#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)

#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))

using namespace std;
using ll = long long;
using vel = vector<ll>;
using ves = vector<string>;
using veb = vector<bool>;
using qul = queue<ll>;

void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

int binary_search(ll x, vel a){
    auto ite = lower_bound(ALL(a), x);
    if(ite != a.end() && *ite == x) {
        return ite - a.begin() ;
    } else {
        return -1;
    }

}

ll modpow(ll a, ll n, ll mod) {
    if(n == 0)
        return 1;
    if(n == 1)
        return a % mod;
    if(n % 2 == 1)
        return (a * modpow(a, n - 1, mod)) % mod;
    ll t = modpow(a, n / 2, mod);
    return (t * t) % mod;
}

int main() {
    ll K, S, ans = 0, z;
    cin >> K >> S;
    REP(x, K+1){
        REP(y, K+1){
            z = S - x - y;
            if(z >= 0 && z <= K) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}