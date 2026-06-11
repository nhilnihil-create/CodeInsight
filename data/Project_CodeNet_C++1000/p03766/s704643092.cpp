#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+7,mod=1000000007;
int n,m,ans,f[N],s[N];
int main()
{
	scanf("%d",&n);
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3)f[i]=(f[i]+s[i-3])%mod;
		f[i]=(f[i]+f[i-1])%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	ans=1ll*f[n]*n%mod;
	for(int i=1;i<n;i++)ans=(ans+1ll*f[i]*(n-1)%mod*(n-1)+1ll*f[i]*min(i+1,n-1))%mod;
	printf("%d\n",ans);
}