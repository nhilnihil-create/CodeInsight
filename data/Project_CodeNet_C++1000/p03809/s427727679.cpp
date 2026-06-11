#include<bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;
vector<int> G[N];
int n,a[N],d[N],rt;
void GG(){ printf("NO"); exit(0);}
void dfs(int t,int fa)
{
	int i; LL Max=0,x,sum=0;
	if(d[t]==1) return ;
	for(i=0;i<G[t].size();i++)
		if(G[t][i]!=fa) dfs(G[t][i],t);
	for(i=0;i<G[t].size();i++)
		if(G[t][i]!=fa)
			sum+=a[G[t][i]],Max=max(Max,1LL*a[G[t][i]]);
	x=sum-a[t];
	if(x<0||2*x>sum) GG();
	if(Max*2>sum&&x>sum-Max) GG();
	a[t]=sum-2*x;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		G[x].push_back(y),d[x]++;
		G[y].push_back(x),d[y]++;
	  }
	for(i=1;i<=n;i++)
		if(d[i]!=1) rt=i;
	if(rt==0){
		if(a[1]!=a[2]) GG();
		else printf("YES");
		return 0;
	  }
	dfs(rt,0);
	if(a[rt]!=0) GG();
	printf("YES");
	return 0;
}
