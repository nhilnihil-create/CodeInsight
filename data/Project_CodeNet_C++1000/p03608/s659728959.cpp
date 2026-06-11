//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

const ll MXN=200;
ll d[MXN][MXN];
vl r;
ll N,M,R;

ll dfs(vl r){
  ll x=0;
  rep(i,R-1){
    x+=d[r[i]][r[i+1]];
  }
  return x;
}

int main() {
  cin >> N >> M >> R;
  r.resize(R);
  rep(i,R){
    cin >> r[i];
    r[i]--;
  }
  sort(r.begin(),r.end());
  rep(i,N){
    rep(j,N){
      d[i][j]=INF;
    }
  }
  ll ans=INF;
  rep(i,M){
    ll A,B,C;
    cin >> A >> B >> C;
    A--;B--;
    d[A][B]=C;
    d[B][A]=C;
  }
  rep(k,N){
    rep(i,N){
      rep(j,N){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  ans=dfs(r);
  while(next_permutation(r.begin(),r.end())){
    ans=min(ans,dfs(r));
  }
  cout << ans << endl;
}
