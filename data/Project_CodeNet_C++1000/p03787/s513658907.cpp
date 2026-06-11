#include <bits/stdc++.h>
#define N 500006
using namespace std;
struct arr{int to,ne;}e[N];
int n,c,m,st,py,cnt,tot,x,y,head[N],d[N],num[N],sum[N];bool v[N];long long ans;
void add(int x,int y)
{
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}
void dfs(int x,int fa)
{
	v[x]=1;d[x]=d[fa]+1;py++;
	for(int i=head[x];i;i=e[i].ne){
		if(!v[e[i].to])dfs(e[i].to,x);
		else if((d[x]-d[e[i].to])%2==0)num[tot]=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)if(!v[i]){
		py=0;num[++tot]=2;dfs(i,0);
		if(py==1)tot--,st++;else sum[num[tot]]++,ans+=num[tot];
	}
	for(int i=1;i<=tot;i++){
		if(num[i]==1)ans+=(sum[1]-1)+sum[2];
		else ans+=sum[1]+2LL*(sum[2]-1);
	}
	ans+=2LL*st*n-1LL*st*st;
	cout<<ans<<endl;
}
