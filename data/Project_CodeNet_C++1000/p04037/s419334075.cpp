#include<bits/stdc++.h>
#define f(i,t,n) for(int i=(t);i<=(n);++i)
using namespace std;
int n,a[100005];
namespace Ri_Nai
{
	void pre()
	{
		scanf("%d",&n); 
		f(i,1,n)
			scanf("%d",a+i);
		sort(a+1,a+n+1,greater<int>());
	}
	void Main()
	{
		pre();
		f(i,1,n)
		{
			if(i+1>a[i+1])
			{
				int ans=0;
				for(int j=i+1;a[j]==i;++j)ans^=1;
				ans|=(a[i]-i)&1;
				if(ans)puts("First");
				else puts("Second");
				return ;
			}
		}
	}
}
int main()
{
	Ri_Nai::Main();
}
