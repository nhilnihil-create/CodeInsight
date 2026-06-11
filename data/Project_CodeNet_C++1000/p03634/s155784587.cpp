#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<pair<ll,ll>>> to(100001,vector<pair<ll,ll>>(0));
vector<ll> dist(100001,0);

void dfs(ll n,ll p,ll d){
  dist[n] = d;
  for(auto next : to[n]){
    if(next.first == p) continue;
    dfs(next.first,n,d+next.second);
  }
  return;
}

int main(){
  ll n;
  cin >> n;
  rep(i,n-1){
    ll a,b,c;
    cin >> a >> b >> c;
    to[a].push_back(make_pair(b,c));
    to[b].push_back(make_pair(a,c));
  }//rep_i
  ll q,k;
  cin >> q >> k;
  dfs(k,0,0);
  rep(i,q){
    ll x,y;
    cin >> x >> y;
    cout << dist[x]+dist[y] << endl;
  }
}
