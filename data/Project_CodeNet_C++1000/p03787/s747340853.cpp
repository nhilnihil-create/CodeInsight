#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5+10; 
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
vi G[N];
int vis[N];
int flag;
void dfs(int v,int c){
	vis[v] = c;
	for(auto it : G[v]){
		if(vis[it] == 0){
			dfs(it,1^2^c);
		}
		else if(vis[it] == c){
			flag = 0;
		}
	}
}
int main(){
  fast;
  int n,m;cin >> n >> m;
  FOR(i,1,m){
  	int u,v;cin >> u >> v;
  	G[u].pb(v);G[v].pb(u);
  }
  fill(vis,0);
  int bip = 0;
  int nbip = 0;
  int iso = 0;
  FOR(i,1,n){
  	if(vis[i] == 0){
  		if(sz(G[i]) == 0){
  			iso++;
  			continue;
  		}
  		flag = 1;
  		dfs(i,1);
  		if(flag)bip++;
  		else nbip++;
  	}
  }
  ll ans = 0;
  //cout << bip << " " << nbip << " " << iso << "\n";
  ans += 2LL*n*iso;
  ans -= 1LL*iso*iso;
  ans += 2LL*bip*bip;
  ans += 2LL*(bip)*(nbip);
  ans += 1LL*(nbip)*(nbip);
  cout << ans << "\n";
  return 0;
}