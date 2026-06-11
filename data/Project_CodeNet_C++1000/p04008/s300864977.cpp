#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ll x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

ll ans = 0;
ll k;

// 隣接リスト
vvll g(100010, vll());
vi visited(100010, 0);

// グラフに対する深さ優先探索
ll dfs(ll node, ll parent){
    visited[node] = 1;
    ll height = 0;
    rep(i, SZ(g[node])){
        if(!visited[g[node][i]]){
            chmax(height, dfs(g[node][i], node));
        }
    }
    if(height == k-1){
        if(parent != 1){
            ans++;
        }
        return 0;
    }else{
        return height+1;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n >> k;
    vll a(n+1, 0);
    rep(i, n){
        cin >> a[i+1];
    }
    if(a[1] != 1){
        ans++;
        a[1] = 1;
    }
    if(k == 1){
        repr(i, 2, n+1){
            ans += (a[i] != 1);
        }
    }else if(k >= n-1){
    }else{
        repr(i, 2, n+1){
            g[a[i]].push_back(i);
        }
        dfs(1, 1);
    }
    dump(a);
    cout << ans << endl;
    return 0;
}