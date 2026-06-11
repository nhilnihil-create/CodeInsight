#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct edge{
    ll now,to,cost;
    edge(ll now,ll to,ll cost):now(now),to(to),cost(cost) {}
};
int main(){
 int n,m;
 cin>>n>>m;
 V<edge> e;
 for(int i=0;i<m;i++){
     ll a,b,c;
     cin>>a>>b>>c;
     e.emplace_back(a-1,b-1,-c);
 }
 V<ll> d(n,inf);
 d[0]=0;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(d[e[j].now]>=inf)continue;
          chmin(d[e[j].to],d[e[j].now]+e[j].cost);
      }
  }
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(d[e[j].now]>=inf)continue;
          if(chmin(d[e[j].to],d[e[j].now]+e[j].cost)){
              d[e[j].to]=-inf;
          }
      }
  }
  if(d[n-1]<=-inf)cout<<"inf"<<"\n";
  else cout<<-d[n-1]<<"\n";
}