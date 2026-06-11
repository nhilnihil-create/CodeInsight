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

int main(){
    int N, M, R;
    cin >> N >> M >> R;
    int r[R];
    rep(i, R) {cin >> r[i]; r[i]--;}
    int dp[N][N];
    fill(dp[0], dp[N], inf);
    rep(i, M){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        chmin(dp[u][v], c), chmin(dp[v][u], c);
    }
    rep(i, N) dp[i][i] = 0;

    rep(k, N){
        rep(i, N){
            rep(j, N) chmin(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }

    vector<int> v(R);
    iota(all(v), 0);
    int ans = inf;
    do{
        int tmp = 0;
        rep(i, R-1) tmp += dp[r[v[i]]][r[v[i+1]]];
        chmin(ans, tmp);
    } while(next_permutation(all(v)));
    
    cout << ans << endl;
}