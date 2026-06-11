#include<bits/stdc++.h>
using namespace std;

long long a[100100];
long long sum,dif[100100];
long long mx,sum2;
long long k,cou;

main()
{
	long long n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}//*
	if(sum%((n*(n+1))/2)!=0)
	{
		printf("NO\n");
		return 0;
	}
	k=sum/((n*(n+1))/2);
	//*/
	a[n]=a[0];
	n++;
	for(int i=0;i<n-1;i++)
	{
		dif[i]=a[i+1]-a[i];
		//printf("%lld ",dif[i]);
		mx=max(mx,dif[i]);
		sum2+=dif[i];
	}
	if(sum2!=0)
	{
		printf("NO\n");
		return 0;
	}
	//printf("\n");
	n--;
	for(int i=0;i<n;i++)
	{
		//printf("%lld %lld\n",dif[i],k-dif[i]);
		if(k-dif[i]<0)
		{
			printf("NO\n");
			return 0;
		}
		if((k-dif[i])%n!=0)
		{
			printf("NO\n");
			return 0;
		}//*
		else
		{
			cou+=((k-dif[i])/n);
			//printf("%lld\n",(mx-dif[i])/n);
		}//
	}
	//*
	//printf("%lld %lld\n",cou,mx);
	if(cou!=k)
	{
		printf("NO\n");
		return 0;
	}//*/
	printf("YES\n");
}