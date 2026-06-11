#include<bits/stdc++.h>
using namespace std;

long long n,x,a[2050];
long long mn[2050][2050];

main()
{
	scanf("%lld %lld",&n,&x);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		mn[0][i]=a[i];
		ans+=mn[0][i];
	}
	for(int i=1;i<n;i++)
	{
		long long sum=0;
		for(int j=0;j<n;j++)
		{
			int chk=j-i;
			if(chk<0)
				chk=n+chk;
			mn[i][j]=min(mn[i-1][j],a[chk]);
			sum+=mn[i][j];
		}
		ans=min(ans,sum+i*x);
	}
	printf("%lld\n",ans);
}
