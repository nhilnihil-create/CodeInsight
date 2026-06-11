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


const int M=2005;
const int N=M*M;
const int mo=1e9+7;

int n,m,jc[N],inv[N],f[M][M];

inline int ksm(int x,int y)
{
	int ret=1ll;
	while(y)
	{
		if(y&1) ret=ret*x%mo;
		x=x*x%mo;
		y>>=1ll;
	}
	return ret%mo;
}

inline void Add(int &x,int y)
{
	x+=y;
	if(x>=mo) x%=mo;
}

inline int C(int x,int y)
{
	return jc[x]*inv[y]%mo*inv[x-y]%mo;
}

signed main()
{
	n=read();
	m=read();
	if(m==1) return puts("1"),0;
	inv[0]=jc[0]=1;
	for ( int i=1;i<=n*m;i++ ) jc[i]=jc[i-1]*i%mo;
	for ( int i=1;i<=n*m;i++ ) inv[i]=ksm(jc[i],mo-2)%mo;
	for ( int i=1;i<=n;i++ ) f[i][0]=1;
	for ( int i=1;i<=n;i++ ) 
		for ( int j=1;j<=i;j++ ) 
		{
			f[i][j]=(f[i][j]+f[i-1][j]+mo)%mo;
			f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-j+1)%mo*C(n-i+(n-j+1)*(m-1)-1,m-2)%mo+mo)%mo;
		}
	printf("%lld\n",(f[n][n]+mo)%mo);
	return 0;
}
			