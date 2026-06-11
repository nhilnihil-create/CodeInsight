#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define LL long long
#define Max 100005
using namespace std;
LL  N,A,B,data[Max];
bool c(LL x)
{
	LL sum=0;
	for(int i=0;i<N;i++)
	{
		LL t=data[i]-(x*B);
		if(t>0)
		{
			sum+=ceil(t*1.0/(A-B));
			if(sum>x)
				return false;
		}
	}
	return true;
}
int main()
{
	scanf("%lld%lld%lld",&N,&A,&B);
	LL l=0,r=0;
	for(LL i=0;i<N;i++)
	{
		scanf("%lld",&data[i]);
		r=max(r,data[i]);
	}
	while(l<r)
	{
		LL mid=(l+r)/2;
		if(c(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
}
