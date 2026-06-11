#include<bits/stdc++.h>
using namespace std;

main()
{
	long long a,b,n;
	scanf("%lld %lld %lld",&n,&a,&b);
	a-=b;
	vector<long long> v(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	long long l=1,r=1e10;
	while(l<=r)
	{
		//printf("%lld %lld\n",l,r);
		if(l==r)
		{
			printf("%lld\n",l);
			return 0;
		}
		long long mid=(l+r)/2;
		long long com=mid*b,use=mid;
		//printf("%lld\n",com);
		for(int i=0;i<n;i++)
		{
			if(v[i]-com>0)
			{
				use-=(v[i]-com)/a;
				//printf("%lld:%lld\n",i+1,use);
				if((v[i]-com)%a!=0)use--;
			}
		}
		if(use<0)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
}