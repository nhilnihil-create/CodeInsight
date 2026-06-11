#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 100005;
const LL inf = 1ll<<50;

LL f[maxn][3];
char c[maxn][5];int n,a[maxn];

int main()
{
	#ifdef Amberframe
		freopen("arc066c.in","r",stdin);
		freopen("arc066c.out","w",stdout);
	#endif
	scanf("%d %d",&n,&a[0]);
	for (int i=1;i<n;i++)
		scanf("%s %d",c[i],&a[i]);
	f[0][0]=a[0];f[0][1]=f[0][2]=-inf;
	
	for (int i=1;i<n;i++)
	if (*c[i]=='-') {
		f[i][0]=-inf;
		f[i][1]=f[i-1][0]-a[i];
		f[i][2]=f[i-1][1]+a[i];
		f[i][1]=max(f[i][1],f[i][2]);
		f[i][0]=max(f[i][0],f[i][1]);
	}
	else {
		f[i][0]=f[i-1][0]+a[i];
		f[i][1]=f[i-1][1]-a[i];
		f[i][2]=f[i-1][2]+a[i];
		f[i][1]=max(f[i][1],f[i][2]);
		f[i][0]=max(f[i][0],f[i][1]);
	}
	printf("%lld",f[n-1][0]);
	return 0;
}