#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

//素因数分解
vector<pair<ll,int>> factorize(ll n) {
    vector<pair<ll,int>> res;
    ll N = n;
    for (ll i = 2; i * i <= N; i++) {
        if (n % i != 0) continue;
        res.emplace_back(i,0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        } 
    }
    if (n != 1) res.emplace_back(n,1);
    return res;
}

int main() {
    int n; cin >> n;
    map<ll,ll> mp;
    for (int i = 2; i <= n; i++) {
        vector<P> p = factorize(i);
        rep(j,p.size()) {
            mp[p[j].first] += p[j].second;
        }
    }
    ll ans = 1;
    for (pair<ll,ll> p : mp) {
        ans *= p.second+1;
        ans %= mod;
    }
    cout << ans << endl;
}