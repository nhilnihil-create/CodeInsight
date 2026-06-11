#include <bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int n,k,a[maxn],f[maxn],head[maxn],to[maxn],nxt[maxn],tot,ans;

void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}

void dfs(int x){
	for(int i=head[x],y;i;i=nxt[i]){
		y=to[i];
		dfs(y);
		f[x]=max(f[x],f[y]+1);
	}
	if(f[x]==k-1&&a[x]!=1){
		f[x]=-1;
		ans++;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i],i);
	}
	if(a[1]!=1){
		ans++;
		a[1]=1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}