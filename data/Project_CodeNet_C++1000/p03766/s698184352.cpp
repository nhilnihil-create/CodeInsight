#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,ans,i,j,k,f[1000005],s[1000005];
int main()
{
	scanf("%d",&n);
	f[1]=n;
	s[1]=(n-1+n)%md;
	for(i=2;i<=n;++i)
	{
		f[i]=f[i-1];
		if(i-3>=0)
			f[i]=(1ll*f[i]+s[i-3])%md;
		f[i]=(f[i]+1ll*(n-max(2,i-1)+1)*n)%md;
		s[i]=(1ll*s[i-1]+n-1+f[i])%md;
	}
	printf("%d",f[n]);
	return 0;
}
