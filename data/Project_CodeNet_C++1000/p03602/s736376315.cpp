#include<cstdio>
#include<cstdlib>
using namespace std;
int a[310][310];
void broke(int x){
	printf("%d\n",x);
	exit(0);
}
int main(){
//	freopen("D.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(a[i][k]+a[k][j]<a[i][j])
					broke(-1);
	bool bo;
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			bo=1;
			for(int k=1;k<=n;k++)
				if(k!=i&&k!=j&&a[i][k]+a[k][j]==a[i][j]){
					bo=0;
					break;
				}
			ans=ans+a[i][j]*bo;
		}
	printf("%lld\n",ans/2);
	return 0;
}
