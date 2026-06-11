#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+100,mod=1e9+7;
int n;
LL f[N],s[N],Ans;

void Inc(LL &x,LL y) {x+=y, x>=mod ? x-=mod : 233;}

int main()
{
	scanf("%d",&n);
	f[0]=s[0]=1;
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		if(i>2) Inc(f[i],s[i-3]);
		s[i]=s[i-1], Inc(s[i], f[i]);
		//cout<<f[i]<<endl;
	}
	for(int i=0;i<=n-2;++i)
	{
		Inc(Ans,1ll*(n-1)*(n-1)%mod*f[i]%mod),
		Inc(Ans,1ll*(i+1)*f[i]%mod);
	}
	Inc(Ans,f[n-1]*(n-1)%mod); Inc(Ans,f[n]); printf("%lld",Ans);
	return 0;
}