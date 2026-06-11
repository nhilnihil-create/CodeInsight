#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<int>edge[100005];
int col[100005];
bool bad[100005];
bool used[100005];
vector<int>C; int cnt;
void dfs(int v,int p,int c){
	if(used[v]) return;
	used[v] = 1; if(col[v] && col[v]!=c) bad[p]=1;
	col[v] = c; cnt++;
	for(int i=0;i<edge[v].size();i++){
		if(used[edge[v][i]] == 0){
			dfs(edge[v][i],p,-1*c);
		}
		else if(col[edge[v][i]] && col[edge[v][i]]==c)bad[p]=1;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	ll ans = 0; int cnt2;
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		cnt=0;
		dfs(i,i,1);
		if(cnt==1);
		else if(bad[i]) ans++;
		else ans+=2;
		if(cnt!=1) C.pb((bad[i]?1:2)); else cnt2++;
	}
	ans+=1LL*n*n-1LL*(n-cnt2)*(n-cnt2);
	//cout<<ans<<endl;
	for(int i=0;i<C.size();i++){
		for(int j=i+1;j<C.size();j++){
			if(C[i]==2&&C[j]==2) ans+=4;
			else ans+=2;
		}	
	}
	cout<<ans<<endl;
}