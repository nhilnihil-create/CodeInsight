#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1e16;
ll fac[MAX], finv[MAX], inv[MAX];
//ダイクストラ法は負の経路があるとき使えない→ベルマンフォード法
//単一終点ならedgeの向きを逆にして考える
int main(){
  ll v;cin>>v;
  vector<vp> g(v);vll dis(v,MOD),prev(v,-1);
  rep(i,0,v-1){
    ll s,t,d;cin>>s>>t>>d;
    s--;t--;
    g[s].push_back(make_pair(t,d));
    g[t].push_back(make_pair(s,d));
  }
  ll q,k;cin>>q>>k;
  vll x(q),y(q);
  rep(i,0,q){
    cin>>x[i]>>y[i];
    x[i]--;y[i]--;
  }
  priority_queue<P,vector<P>,greater<P> > pq;
  dis[k-1]=0;
  pq.push(make_pair(dis[k-1],k-1));
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    ll from=p.second;
    if(dis[from]<p.first)continue;
    for(auto &edge:g[from]){
      if(dis[edge.first]>dis[from]+edge.second){
        dis[edge.first]=dis[from]+edge.second;
        prev[edge.first]=from;
        pq.push(make_pair(dis[edge.first],edge.first));
      }
    }
  }
  rep(i,0,q){
    cout<<dis[x[i]]+dis[y[i]]<<endl;
  }
}



