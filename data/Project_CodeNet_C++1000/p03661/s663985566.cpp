#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;

LL Fab(LL x)
{
	return (x>0)?(x):(-x);
}

int main()
{
	int n;
	scanf("%d",&n);
	LL *a=new LL[n];
	LL sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		sum+=a[i];
	}
	LL sum_temp=a[0];
	LL min_diff=Fab(sum-2*sum_temp);
	for(int i=1;i<n-1;i++)
	{
		sum_temp+=a[i];
		if(min_diff>Fab(sum-2*sum_temp))
			min_diff=Fab(sum-2*sum_temp);
	}
	printf("%lld",min_diff);
	return 0;
}