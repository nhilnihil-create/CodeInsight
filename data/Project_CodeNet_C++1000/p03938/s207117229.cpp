#include<cstdio>
#include<algorithm>
using namespace std;
int pos[20005],n,i,x,sum[20005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pos[x]=i;
	}
	for(i=1;i<=n;i++)sum[i]=pos[i]+sum[i-1];
	for(i=1;i<n;i++)printf("%d ",sum[i]);
	printf("%d\n",sum[n]);
	for(i=1;i<n;i++)printf("%d ",n*(1+n)/2-sum[i-1]);
	printf("%d\n",n*(1+n)/2-sum[n-1]);
	return 0;
} 