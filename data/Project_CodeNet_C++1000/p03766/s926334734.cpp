#include <bits/stdc++.h>
using namespace std;

const int mo=int(1e9+7);
int n,f[1000010],ans;

void work()
{
	scanf("%d",&n);
	f[0]=1,f[1]=1;
	for (int i=2,s=2; i<=n; i++)
		f[i]=(s+mo-f[i-2])%mo,s=(s+f[i])%mo;
	for (int i=0; i<=n-2; i++)  ans=(ans+(1LL*(n-1)*(n-1)+(i+1))%mo*f[i])%mo;
	ans=(ans+1LL*f[n-1]*(n-1)+f[n])%mo;
	printf("%d",ans);
}

int main()
{
	work();
	return 0;
}
