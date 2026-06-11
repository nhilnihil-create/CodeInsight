#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
ll n,num[1000005],sum,ans=0;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
	}
	if(sum%((n+1)*n/2)){printf("NO");return 0;}
	sum/=(n+1)*n/2;int tmp=num[1];
	for(int i=1;i<n;i++)
	{
		num[i]-=num[i+1];
	}num[n]-=tmp;
	for(int i=1;i<=n;i++)
	{
		if(num[i]<-sum||(num[i]+sum)%n)
		{printf("NO");return 0;}
		ans+=(sum+num[i])/n;
	}
	if(ans==sum)printf("YES");
	else printf("NO");
	return 0;
}