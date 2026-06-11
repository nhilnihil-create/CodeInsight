#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
// #define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
 
/*--------------------------------------------------------------------------------
 
--------------------------------------------------------------------------------*/


int main() {
    string s; cin >> s;
    ll n = sz(s);
    ll ans = n*(n-1)/2; // COM(n, 2)
    Vl c(26);
    rep(i, 0, n){
        c[s[i]-'a']++;
    }
    rep(i, 0, 26){
        ll m = c[i];
        if(m < 2) continue;
        ans -= m*(m-1)/2; // COM(m, 2)
    }
    co(ans+1);

    return 0;
}