#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rnfor(i,a,b) for(ll (i) = (a) - 1; (i) >= (b); --(i))
#define ll long long
#define mod (1000000007)
#define inf (1e9);
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
    rep1(i, n)t *= i;
    return t;
}

ll combinations(ll n, ll k) {
    ll r = 1;
    rep1(i, k)r = r * n-- / i;
    return r;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m),c(m);
    ll g[n][n];
    rep0(i, n)rep0(j, n){
        if(i == j)g[i][j] = 0;
        else g[i][j] = inf;
    }
    
    rep0(i, m){
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];
        g[a[i]][b[i]] = min(g[a[i]][b[i]],c[i]);
        g[b[i]][a[i]] = min(g[b[i]][a[i]],c[i]);
    }
    
    rep0(k,n)rep0(i, n)rep0(j, n)if(g[i][k] + g[k][j] < g[i][j])g[i][j] = g[i][k] + g[k][j];
    ll ans = m;
    rep0(i, m){
        bool f = false;
        rep0(j, n)if(g[j][a[i]]+c[i]==g[j][b[i]]) f = true;
        if(f)--ans;
    }
    pf(ans);
    return 0;
}
