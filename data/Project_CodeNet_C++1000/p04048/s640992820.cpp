#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,x,b[4],k,ans;
int main()
{
	scanf("%lld %lld",&n,&x);
	ans=n;
	b[0]=n-x,b[1]=x,b[2]=n-x,b[3]=x;
	while(b[0])
	{
		if(b[0]>=b[3])
		{
			x=b[0]/b[3];
			b[0]-=x*b[3];
			b[2]-=x*b[3];
			ans+=b[3]*x*2;
			if(!b[0])ans-=b[3];
		}
		else
		{
			x=b[3]-b[0];
			x=(x-1)/b[2]+1;
			b[3]-=x*b[2];
			b[1]-=x*b[2];
			ans+=b[2]*x*2;
		}
	}
	printf("%lld",ans);
}