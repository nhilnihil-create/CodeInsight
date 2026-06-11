#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e12);
const ll mod = ll(1e9) + 1;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n){
        t *= i;
        t %= mod;
    }
    return t;
}

ll power(ll a, ll b){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = power(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}

ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = 1;
    for(ll i = 0; i < b; i++) {
        ans *= (a - i);
        ans %= mod;
        ans *= power(i + 1, mod - 2);
        ans %= mod;
    }
    return ans;
}
int main(){
    ll n,l,a,b;
    cin >> n >> l >> a;
    rep1(i, n - 1){
        cin >> b;
        if(a + b >= l){
            pf("Possible");
            rep1(j, i - 1)pf(j);
            rrep1(j, n - 1){
                pf(j);
                if(j == i)break;
            }
            return 0;
        }
        a = b;
    }
    pf("Impossible");
    return 0;
}
