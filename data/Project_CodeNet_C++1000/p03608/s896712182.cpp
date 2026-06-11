#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<vector<ll>> d(210,vector<ll>(210, 1e18));
vector<ll> r(10);


void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

ll dfs(ll R, ll cnt, ll flag, ll sum, ll cur){
    if(cnt == R - 1){
        return sum;
    }
    ll m = 1e18;
    rep(i,R){
        if(((1LL) << i) & flag) continue;
        cmin(m, dfs(R, cnt+1, flag | ((1LL) << i), sum + d[cur][r[i]], r[i]));
    }
    return m;
}

int main(){
    ll N,M,R;
    cin >> N >> M >> R;
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    vector<vector<ll>> G(N),C(N,vector<ll>(N));
    ll a,b,c;
    rep(i,M){
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd(N);
    ll ans = 1e18;
    rep(i,R){
        cmin(ans, dfs(R, 0, ((1LL) << i), 0, r[i]));
    }
    cout << ans << endl;
}

