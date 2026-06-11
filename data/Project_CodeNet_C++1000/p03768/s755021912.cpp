#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, M, Q;
    cin >> N >> M;
    vector<int> es[N];
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        es[a].pb(b), es[b].pb(a);
    }
    rep(i, N){
        es[i].pb(i);
    }
    cin >> Q;
    //dp[u][i]:=uから距離iの点を塗る操作が最後に行われたのは何回目か
    int dp[N][11];
    fill(dp[0], dp[N], -1);
    int c[Q];
    rep(i, Q){
        int v, d;
        cin >> v >> d >> c[i];
        v--;
        dp[v][d] = i;
    }
    rep3(i, 9, 0){
        rep(u, N){
            for(auto &v: es[u]){
                dp[u][i] = max(dp[u][i], dp[v][i+1]);
            }
        }
    }
    rep(u, N){
        if(dp[u][0] == -1) cout << 0 << endl;
        else cout << c[dp[u][0]] << endl;
    }
}