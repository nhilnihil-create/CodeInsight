#include<cstdio>
#include<cmath>
using namespace std;
long long a[200001];
int main()
{
	int n,i;
	scanf("%lld",&n);
	long long sum2=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum2+=a[i];
	}
	long long sum1=a[0];
	sum2-=a[0];
        long long x_y=abs(sum1-sum2);
	long long temp;
	for(i=1;i<n-1;i++)
	{
		sum1+=a[i];
		sum2-=a[i];
		temp=abs(sum1-sum2);
		if(temp<x_y)
			x_y=temp; 
	}
	printf("%lld",x_y);
	return 0;
}