#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<vector<ll>> G(101);
vector<vector<ll>> dd(101, vector<ll>(101,1e18));
vector<vector<ll>> d(101, vector<ll>(101,1e18));
void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main(){
    ll N,M;
    cin >> N >> M;
    ll a,b,c;
    vector<Pll> ed(M);
    rep(i,M){
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
        ed[i] = Pll(a,b);
    }
    rep(i,N){
        d[i][i] = 0;
    }
    dd = d;
    warshall_floyd(N);
    ll ans = 0;
    rep(i,M){
        bool flag = 0;
        rep(j,N){
            //if(ed[i].fi == j || ed[i].se == j) continue;
            if(d[ed[i].fi][j] == dd[ed[i].fi][ed[i].se] + d[ed[i].se][j]){
                flag = 1;
                break;
            }
        }
        if(!flag) ans++;
    }
    cout << ans << endl;
}