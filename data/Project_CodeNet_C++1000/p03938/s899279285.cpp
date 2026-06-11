#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=20005;
int n,s[N],ds[N],da[N],db[N],i,j,k,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&j);
		s[j]=i;
	}
	for(i=1;i<n;++i)
		ds[i]=s[i+1]-s[i];
	k=0;
	for(i=1;i<n;++i)
	{
		da[i]=ds[i]+1;
		db[i]=1;
		k=min(k,da[i]);
	}
	for(i=1;i<n;++i)
		da[i]+=-k+1,db[i]+=-k+1;
	a[1]=1,b[1]=s[1]-1;
	for(i=2;i<=n;++i)
	{
		a[i]=a[i-1]+da[i-1];
		b[i]=b[i-1]-db[i-1];
	}
	for(i=1;i<=n;++i)
		b[i]+=-b[n]+1;
	for(i=1;i<=n;++i)
		printf("%d ",a[i]);
	puts("");
	for(i=1;i<=n;++i)
		printf("%d ",b[i]);
	return 0;
}
