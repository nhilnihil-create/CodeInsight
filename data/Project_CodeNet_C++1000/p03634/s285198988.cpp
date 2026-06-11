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
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

const ll MXN=100005;
vector<edge> G[MXN];
vector<bool> B(MXN,false);
vl ans(MXN);

void bfs(ll x,ll d){
  B[x]=true;
  ans[x]=d;
  ll k=G[x].size();
  rep(i,k){
    if(B[G[x][i].to]==false){
      bfs(G[x][i].to,G[x][i].cost+d);
    }
  }
}

  
int main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  ll N;
  cin >> N;
  rep(i,N-1){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }
  ll Q,K;
  cin >> Q >> K;
  K--;
  bfs(K,0);
  rep(i,Q){
    ll x,y;
    cin >> x >> y;
    x--;y--;
    cout << ans[x]+ans[y] << endl;
  }
}