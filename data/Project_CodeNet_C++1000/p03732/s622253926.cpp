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
using P = pair<ll,ll>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 2*1e5;
const int mod = 1e9+7;

vvll W;
ll w_min;
int N, w_upper;

ll dfs(int n, int value, int sum, vint &x) {
    if (n == 3) {
        x[n] = N-sum;
        ll res = 0;
        ll weight = 0;
        rep(i,4) {
            if (x[i] > W[i].size()) return 0;
            weight += (w_min+i)*x[i];
        }
        if (weight > w_upper) return 0;
        rep(i,4)rep(j,x[i]) res += W[i][j];
        return res;
    }

    ll ans = 0;
    x[n] = value;
    for (int i = 0; i <= N-sum; i++) {
        ans = max(ans,dfs(n+1,i,sum+i,x));
    }
    return ans;

}

int main() {
    vint x(4);
    cin >> N >> w_upper;
    W.resize(4);
    rep(i,N) {
        int w, v; cin >> w >> v;
        if (i == 0) w_min = w;
        W[w-w_min].push_back(v);
    }
    rep(i,4) sort(rall(W[i]));
    ll ans = 0;
    rep(i,N+1) ans = max(ans,dfs(0,i,i,x));
    cout << ans << endl;
}