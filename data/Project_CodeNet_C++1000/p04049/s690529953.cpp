#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 2e3;
vector<int> es[MAX_V];
int d[MAX_V][MAX_V];

void dfs(int root, int now, int pre){
    if(now == root) d[root][now] = 0;
    else d[root][now] = d[root][pre]+1;
    for(auto &e: es[now]){
        if(e != pre) dfs(root, e, now);
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    rep(i, N) dfs(i, i, -1);
    int ans = N;
    if(K%2 == 0){
        rep(i, N){
            int tmp = 0;
            rep(j, N){
                if(d[i][j] > K/2) tmp++;
            }
            chmin(ans, tmp);
        }
    }
    else{
        rep(i, N){
            for(auto &e: es[i]){
                int tmp = 0;
                rep(j, N){
                    if(d[i][j] > K/2 && d[e][j] > K/2) tmp++;
                }
                chmin(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
