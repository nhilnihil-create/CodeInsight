#include<stdio.h>

long long int abs_1(long long int i){
	if(i<0) return -i;
	else return i;
}
int main()
{
	 int N,i,j;
	 long long int sum1=0,sum=0;
	scanf("%d",&N);
	long long int a[200000]={0},x,min=2e+9;
	for(i=0;i<N;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for(i=0;i<N-1;i++)
	{
		sum1+=a[i];
		x=abs_1(2*sum1-sum);
		if(x<=min)
		{
			min=x;
		}
	}
	printf("%lld",min);
	return 0;
}