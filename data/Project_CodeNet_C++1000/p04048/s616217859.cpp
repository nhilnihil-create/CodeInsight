#include<bits/stdc++.h>

using namespace std;

namespace zzc
{
	long long x,a,b,n,ans;
	
	void work()
	{
		scanf("%lld%lld",&n,&x);
		ans=n;
		a=min(x,n-x);
		b=max(x,n-x);
		while(a)
		{
		    ans+=(b/a)*2*a;
			if(!(b%a))
			{		
				ans-=a;
				break;
			}
			else
			{
				long long tmp=a;
				a=b%tmp;
				b=tmp;
			}
		}
		printf("%lld",ans);
	}
	
}

int main()
{
	zzc::work();
	return 0;
} 