#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ll gcd(ll x,ll y){
  if(x%y==0)return y;
  else return gcd(y,x%y);
}
vector<vector<P>>G(110000);
vector<ll>dist;
void Dij(ll start){
  priority_queue<P,vector<P>,greater<P>> q;
  dist=vector<ll>(110000,INF);
  dist[start]=0;
  q.push(P(start,0ll));
  
  while(!q.empty()){
    ll v=q.top().first;
    ll d=q.top().second;
    q.pop();
    if(dist[v]<d)continue;
    for(auto nv:G[v]){
      if(dist[nv.first]>dist[v]+nv.second){
        dist[nv.first]=dist[v]+nv.second;
        q.push(P(nv.first,dist[nv.first]));
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n;
  cin >> n;
  rep(i,n-1){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(P(b,c));
    G[b].push_back(P(a,c));
  }
  int q,k;
  cin >> q >> k;
  k--;
  Dij(k);
  rep(i,q){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    cout << dist[x]+dist[y] << endl;
  }
}
