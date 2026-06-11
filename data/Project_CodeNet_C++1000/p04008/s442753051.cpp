#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans,a[200001],e[200001],nt[200001],hd[200001],tot;
void build(int t,int k){
	tot++;
	e[tot]=k;
	nt[tot]=hd[t];hd[t]=tot;
}
int dfs(int x,int dep){
	int i,mx=dep;
	for(i=hd[x];i;i=nt[i])mx=max(mx,dfs(e[i],dep+1));
	if(a[x]!=1&&mx-dep==m-1)ans++,mx=0;
	return mx;
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[1]!=1)ans=a[1]=1;
	for(i=2;i<=n;i++)build(a[i],i);
	dfs(1,0);
	printf("%d",ans);
}