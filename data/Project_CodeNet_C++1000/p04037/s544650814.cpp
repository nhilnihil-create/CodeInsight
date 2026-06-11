#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,k,x,a[100005],f[100005][2];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	i=n,j=1;
	while(1)
	{
		if(j+1>a[i-1])
		{
			k=0;
			for(x=i;j<=a[x];--x)
				++k;
			if(k%2==0||(a[i]-j)%2==1)
				printf("First");
			else
				printf("Second");
			return 0;
		}
		--i,++j;
	}
	return 0;
}
