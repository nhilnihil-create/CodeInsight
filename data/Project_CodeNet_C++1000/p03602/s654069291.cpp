#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int n;
LL a[301][301];
bool vis[301][301];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	memset(vis,1,sizeof(vis));
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				if (k==i||k==j) continue;
				if (a[i][k]+a[k][j]<a[i][j]) {
					printf("-1\n");
					return 0;
				}
				if (a[i][k]+a[k][j]==a[i][j]) vis[i][j]=0;
			}
	LL ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (vis[i][j]) ans+=a[i][j];
	printf("%lld\n",ans);
	return 0;
}