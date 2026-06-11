#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,a[105],p[105],g[105][105],len[105];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	if(a[1]*2<a[n])
	{
		printf("Impossible");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(!p[a[i]])
			p[a[i]]=i;
		else if(!p[a[n]-a[i]])
			p[a[n]-a[i]]=i;
		else if(a[i]>(a[n]-1)/2+1)
			g[a[i]-1][++len[a[i]-1]]=i;
		else
		{
			printf("Impossible");
			return 0;
		}
	for(i=0;i<=a[n];++i)
		if(!p[i])
		{
			printf("Impossible");
			return 0;
		}
	printf("Possible");
	return 0;
}
