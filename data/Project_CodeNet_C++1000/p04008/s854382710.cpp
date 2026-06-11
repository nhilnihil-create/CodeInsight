#include "bits/stdc++.h"
#include<assert.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const int inf = 1e17;
const int mod = 1000000007;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int a[100006];
int dis[100006];
vector<int>G[100006];
int ans,n,k;

int dfs(int now,int par){
	if(dis[now]!=-1)return dis[now];
	int res=-1,p=0;
	if(G[now].size()==1&&now){
		return dis[now]=0;
		}
	for(int e:G[now]){
		if(e==par)continue;
		int k2=dfs(e,now);
		if(k2==k-1)p++;
		else res=max(res,k2);
		}
	res++;	
	if(now)ans+=p;
	//cout<<now<<' '<<res<<endl;		
	return dis[now]=res;	
}

signed main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	if(a[0]!=1){
		a[0]=1;ans++;
		}
	for(int i=1;i<n;i++){
		a[i]--;
		G[a[i]].push_back(i);
		G[i].push_back(a[i]);
	}
	rep(i,n)dis[i]=-1;
	
	dfs(0,-1);
	cout<<ans<<endl;	
}
