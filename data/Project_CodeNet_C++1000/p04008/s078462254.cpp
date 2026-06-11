#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int sd[N],fa[N],dis[N],fi[N],f[N],ne[N],tot,zz[N],n,k,a[N],ans;
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x,int y,int z){
	sd[x]=z;fa[x]=y;
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y)dfs(zz[i],x,z+1);
}
int cmp(int x,int y){
	return sd[x]>sd[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),f[i]=i;
	if (a[1]!=1)ans++;
	for (int i=2;i<=n;i++)jb(a[i],i);
	dfs(1,0,0);
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=n;i++)dis[i]=1;
	for (int i=1;i<n;i++){
		if (fa[f[i]]!=1&&dis[f[i]]==k){
			ans++;
			continue;
		}
		dis[fa[f[i]]]=max(dis[fa[f[i]]],dis[f[i]]+1);
	}
	printf("%d",ans);
}