#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
vector<int> E[N];
int dep[N],hal,cnt1,cnt2;
void DFS(int u,int p,int d){
	if(d<=hal)cnt1++;
	if(d==hal+1)cnt2++;
	for(int v:E[u])if(v!=p)DFS(v,u,d+1);
}
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	hal=k/2;
	int ans=n;
	for(int cen=1;cen<=n;cen++){
		cnt1=0;
		int mx=0;
		for(int sub:E[cen]){
			cnt2=0;
			DFS(sub,cen,1);
			mx=max(mx,cnt2);
		}
		ans=min(ans,n-cnt1-(k%2==1?mx:0)-1);
	}
	printf("%i\n",ans);
	return 0;
}