#include<cstdio>
#include<iostream>
#define maxn 100010
using namespace std;
long long n,m,i,j,a[maxn],b[maxn],c[31],t,x,sum,ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	for(j=1;j<=n;j++)
		if((a[j]&m)==a[j])ans+=b[j];
	while(m)
	{
		c[++t]=m&1;
		m>>=1;
	}
	x=(1<<t)-1;
	for(i=t;i;i--)
	{
		x-=1<<(i-1);
		if(c[i])
		{
			sum=0;
			for(j=1;j<=n;j++)
				if((a[j]&x)==a[j])sum+=b[j];
			ans=max(ans,sum);
		}
		if(c[i])x+=1<<(i-1);
	}
	
	cout<<ans<<endl;
}