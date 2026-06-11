#include<bits/stdc++.h>
using namespace std;
int n,a,b;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		if(a&&b)--b,++ans;
		a=b&1;
		ans=ans+(b>>1);
	}
	printf("%lld",ans);
}