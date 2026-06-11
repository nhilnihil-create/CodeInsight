#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define N 100002
using namespace std;
const int mod=1000000007;
const int inf=1<<30;
int n,m,i,x[N],y[N],sum;
int read()
{
	char c=getchar();
	int w=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		w=w*10+c-'0';
		c=getchar();
	}
	return w*f;
}
signed main()
{
	n=read();m=read();
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<=m;i++) y[i]=read();
	sort(x+1,x+n+1);
	sort(y+1,y+m+1);
	for(i=1;i<m;i++) sum=(sum+i*(m-i)%mod*(y[i+1]-y[i])%mod)%mod;
	int ans=0;
	for(i=1;i<n;i++) ans=(ans+i*(n-i)%mod*(x[i+1]-x[i])%mod)%mod;
	printf("%lld\n",ans*sum%mod);
	return 0;
}
