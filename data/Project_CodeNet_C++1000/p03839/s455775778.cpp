#include<bits/stdc++.h>
using namespace std;

long long a[100100],sum[100100];
long long qs[100100],qs2[100100],sum2[100100];

main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1];
		if(a[i]>0)sum[i]+=a[i];
		qs[i]=a[i];
		qs[i]+=qs[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		sum2[i]=sum2[i+1];
		if(a[i]>0)sum2[i]+=a[i];
		qs2[i]=a[i];
		qs2[i]+=qs2[i+1];
	}
	long long ans=0;
	for(int i=k;i<=n;i++)
	{
		//printf("[%lld %lld %lld %lld]\n",sum[i-k+1],qs[i],qs[i-k+1],sum2[i+1]);
		//printf("{%d %d %d %d}\n",i-k,i,i-k,i);
		ans=max(ans,sum[i-k]+max(qs[i]-qs[i-k],(long long)0)+sum2[i+1]);
	}
	//printf("\n");
	/*
	for(int i=1;i+k<=n;i++)
	{
		//printf("[%lld %lld %lld %d]\n",sum2[i+k-1],qs2[i+k-1],qs2[i],i);
		//printf("{%d %d %d %d}\n",i+k,i+k,i,i);
		ans=max(ans,sum2[i+k]-qs2[i+k]+qs2[i]);
	}*/
	printf("%lld",ans);
}