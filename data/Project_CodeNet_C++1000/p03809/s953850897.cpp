#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

const int MAX_V = 1e5;
vector<int> es[MAX_V];
ll A[MAX_V];
bool able = true;

//parからnowに流れてくる量
int dfs(int now, int par){
    vector<ll> v;
    for(auto &e: es[now]){
        if(e != par) v.pb(dfs(e, now));
    }
    if(v.empty()) return A[now];
    ll cnt = 0, M = 0;
    for(auto &e: v){
        cnt += e;
        M = max(M, e);
    }
    //nowより下の部分木の葉同士で結んだ回数、結べる回数
    ll x = cnt-A[now], k;
    if(2*M > cnt) k = cnt-M;
    else k = cnt/2;
    if(x < 0 || x > k) able = false;
    if(par == -1 && (2*k != cnt || A[now] != k)) able = false;
    return max(cnt-2*x, 0ll);
}

int main(){
    int N; cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    if(N == 2){
        if(A[0] == A[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    rep(i, N){
        if(es[i].size() >= 2){
            dfs(i, -1);
            break;
        }
    }
    if(able) cout << "YES" << endl;
    else cout << "NO" << endl;
}