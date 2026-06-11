#include<bits/stdc++.h>
using namespace std;
const int M=5005;
int n,k,sum,a[M],dp[M];
void in()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=min(a[i],k),sum+=a[i];
}
void ac()
{
	sort(a,a+n+1);dp[0]=1;
	for(int i=n,flag=1;i>=0;flag=1,sum-=a[i--])
	{
		for(int j=k-1;j>=k-sum&&j>=0;--j)if(dp[j])flag=0;
		if(flag)printf("%d",i),exit(0);
		for(int j=k;j>=a[i];--j)dp[j]|=dp[j-a[i]];
	}
}
int main(){in();ac();}