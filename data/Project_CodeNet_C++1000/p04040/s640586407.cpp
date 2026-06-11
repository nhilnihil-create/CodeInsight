#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;

inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

const int N=2e5+5;
const int mod=1e9+7;

int n,m,a,b,ans,jc[N],inv[N];

inline int ksm(int x,int y)
{
	int ret=1ll;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1ll;
	}
	return ret;
}

inline int C(int x,int y)
{
	return jc[x]%mod*inv[y]%mod*inv[x-y]%mod;
}

signed main()
{
	n=read();
	m=read();
	a=read();
	b=read();
	jc[0]=1,inv[0]=1;
	for ( int i=1;i<=max(n,m)*2;i++ ) jc[i]=jc[i-1]*i%mod;
	for ( int i=1;i<=max(n,m)*2;i++ ) inv[i]=ksm(jc[i],mod-2)%mod;
	for ( int i=1;i<=n-a;i++ )
		ans=(ans+C(i-1+b-1,i-1)*C(n-i+m-b-1,m-b-1)+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
	