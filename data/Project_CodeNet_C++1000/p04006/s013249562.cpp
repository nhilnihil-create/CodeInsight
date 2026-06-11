#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,i,j,k,l,o,p,ans,a[10010],dp[10010],mn[4050][4050];
int main()
{
	scanf("%lld%lld",&n,&m);
	for (i=1;i<=n;i++)
	 scanf("%lld",a+i),a[i+n]=a[i],ans+=a[i];
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	 {
	 	mn[i][0]=a[i];
	  	mn[i][j]=min(mn[i][j-1],a[n+i-j]);	 	
	 }
	for (k=0;k<=n;k++)
	 {
	 	ll ans1=0;
	 	for (i=1;i<=n;i++)
	 	 ans1+=mn[i][k];
	 	ans=min(ans,ans1+k*m);
	 }
	printf("%lld\n",ans);
}