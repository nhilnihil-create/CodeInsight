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
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    vector<int> x(N);
    rep(i, N) cin >> x[i];
    int L;
    cin >> L;
    int next[N][20];
    rep(i, N){
        next[i][0] = upper_bound(all(x), x[i]+L)-x.begin()-1;
    }
    rep(j, 19){
        rep(i, N){
            next[i][j+1] = next[next[i][j]][j];
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v; u--, v--;
        if(u > v) swap(u, v);
        int ans = 1;
        rep3(j, 19, 0){
            if(next[u][j] < v) u = next[u][j], ans += (1<<j); 
        }
        cout << ans << endl;
    }
}