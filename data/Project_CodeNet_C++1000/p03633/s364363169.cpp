#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

// デバッグを消し忘れるな！！！


ll gcd(ll a, ll b){
    while(1){
        if(a < b) swap(a, b);
        if(!b) break;
        a %= b;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main() {
    ll n; cin >> n;
    Vl t(n);
    rep(i, 0, n) cin >> t[i];

    ll ans = t[0];
    rep(i, 1, n){
        ans = lcm(ans, t[i]);
    }
    co(ans);

    return 0;
}
