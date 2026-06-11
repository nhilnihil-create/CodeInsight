#include "bits/stdc++.h"
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
#define fi first
#define se second
//#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef vector<ll> vi;
typedef pair<int,int> P;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) ((x)>0?(x):-(x))
#define y1 hhf
#define mp make_pair
const int maxn = 5000;
int n;
vi e[maxn];
int ncnt;
int k;
int u,v,w;
int vis[maxn],cnt,d[maxn];
void dfs(int u){
	vis[u]=1;
	if(d[u]<=k&&u<=n) cnt++;
	for(int i=0;i<e[u].size();i++){
		if(vis[e[u][i]]) continue;
		v=e[u][i];
		d[v]=d[u]+1;
		dfs(v);
	}
}
void addedge(int u,int v){
	e[u].pb(v);
	e[v].pb(u);
}
int main(){
	cin>>n>>k;
	ncnt=n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		ncnt++;
		addedge(u,ncnt);
		addedge(v,ncnt);
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=ncnt;i++){
		memset(vis,0,sizeof vis);
		cnt=0;
		d[i]=0;
		dfs(i);
		//cout<<cnt<<endl;
		ans=min(ans,(n-cnt));
	}
	cout<<ans<<endl;
	return 0;
}