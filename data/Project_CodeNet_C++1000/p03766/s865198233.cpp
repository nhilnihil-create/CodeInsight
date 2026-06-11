#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn=1e6+10;
const int mo=1e9+7;

int n,f[maxn],pre[maxn],Ans;

int main()
{
#ifdef h10
	freopen("neutral.in","r",stdin);
	freopen("neutral.out","w",stdout);
#endif
	int i;
	scanf("%d",&n);
	f[0]=pre[0]=1; f[1]=1; pre[1]=2;
	for (i=2;i<=n;i++)
	{
		f[i]=(pre[i-1]+mo-f[i-2])%mo;
		pre[i]=(pre[i-1]+f[i])%mo;
	}
	Ans=f[n];
	for (i=0;i<n-1;i++)
		(Ans+=(LL)f[i]*(i+1)%mo)%=mo;
	(Ans+=(LL)pre[n-2]*(n-1)%mo*(n-1)%mo)%=mo;
	(Ans+=(LL)f[n-1]*(n-1)%mo)%=mo;
	printf("%d\n",Ans);
}
