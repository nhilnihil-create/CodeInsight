#include<iostream>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define N 500005
using namespace std;
int fa[N],f[305][305],n,cnt=0; long long ans=0;
bool vis[305][305];
struct Node{
	int x,y,d;
}a[N];
bool cmp(Node aa,Node bb)
{
	return aa.d<bb.d;
}
int find(int x)
{
	if (x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void make(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&f[i][j]);
	memset(vis,true,sizeof(vis));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			for (int k=1;k<=n;k++){
				if (i==k||j==k) continue;
				if (f[i][j]>f[i][k]+f[k][j]){
					puts("-1");
					return 0;
				}
				else if (f[i][j]==f[i][k]+f[k][j]) vis[i][j]=false;
			}
		}
	}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++) if (vis[i][j]) ans=ans+(long long)f[i][j];
	/*for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if (i==j) continue;
			a[++cnt].x=i; a[cnt].y=j;
			a[cnt].d=f[i][j];
		}
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+cnt+1,cmp);
	int ans=0; int k=0;
	for (int i=1;i<=cnt;i++){
		if (find(a[i].x)!=find(a[i].y)){
			k++;
			ans=ans+a[i].d;
			make(a[i].x,a[i].y);
		}
		else continue;
		if (k==n-1) break;
	}*/
	printf("%lld\n",ans);
	return 0;
}