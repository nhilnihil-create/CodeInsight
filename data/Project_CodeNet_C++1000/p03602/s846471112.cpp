#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=305;

int n;
int a[N][N],b[N][N];

int main()
{

	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]),b[i][j]=(i==j)?0:1e9+1;
	
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) 
		{
			bool o=false;
			for (int l=1;l<=n;l++)
			if (l!=i&&l!=j) 
			{
				if (a[i][l]+a[l][j]<a[i][j]) {puts("-1");return 0;}
				if (a[i][l]+a[l][j]==a[i][j]) {o=true;break;}
			}
			if (!o) b[i][j]=b[j][i]=a[i][j];
		}
	long long ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) if (b[i][j]!=1e9+1) ans+=b[i][j];
	/*for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (b[i][j]!=a[i][j]) {puts("-1");return 0;}*/ 
	printf("%lld",ans);
	return 0;
}
