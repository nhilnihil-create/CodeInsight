#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e9)+1;
const ll mod = ll(1e9)+7;
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
    ll n,ma,mb;
    cin >> n >> ma >> mb;
    vector<ll> a(n),b(n),c(n);
    rep0(i, n)cin >> a[i] >> b[i] >> c[i];
    ll dp[n + 1][401][401];
    rep0(i, n+1)rep0(j, 401)rep0(k, 401)dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep0(i, n){
        rep0(j, 401){
            rep0(k, 401){
                if(dp[i][j][k] == INF)continue;
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                dp[i + 1][j + a[i]][k + b[i]] = min(dp[i][j][k] + c[i], dp[i + 1][j + a[i]][k + b[i]]);
            }
        }
    }
    ll ans = INF;
    rep0(i, 401)rep0(j, 401)if(ma * j == mb * i && i != 0 && j != 0)ans = min(ans,dp[n][i][j]);
    if(ans == INF)pf(-1);
    else pf(ans);
    return 0;
}

