#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ll gcd(ll x,ll y){
  if(x%y==0)return y;
  else return gcd(y,x%y);
}
struct edge{
  int to;
  ll cost;
};
vector<edge>G[100010];
ll dist[100010];
void dfs(int v,int p,ll d){
  dist[v]=d;
  for(auto g:G[v]){
    if(g.to==p)continue;
    dfs(g.to,v,d+g.cost);
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(edge{b,c});
    G[b].push_back(edge{a,c});
  }
  int q,k;
  cin >> q >> k;
  k--;
  dfs(k,-1,0);
  rep(i,q){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    cout << dist[x]+dist[y] << endl;
  }
    
}
