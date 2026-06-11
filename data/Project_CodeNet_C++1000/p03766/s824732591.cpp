#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=1000005,mod=1000000007;
int n,f[N],g[N],ans;

void inc(int &x,LL y)
{
	x=(x+y)%mod;
}

int main()
{
	scanf("%d",&n);
	f[0]=1;
	rep(i,0,n)
	{
		if(i) inc(g[i],g[i-1]),inc(f[i],g[i]);
		if(i==n) inc(ans,f[i]);
		else if(i==n-1) inc(ans,(LL)f[i]*(n-1));
		else inc(ans,(LL)f[i]*(n-1)%mod*(n-1));
		inc(f[i+1],f[i]);
		
		if(i<=n-2)
		{
			int x=max(1,n-i-2);
			if(2<=x) inc(g[i+3],f[i]),inc(g[n],-f[i]);
			inc(f[n],(LL)f[i]*(n-x));
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}