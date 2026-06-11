#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
#define fint register int
#define flint register lint

inline int ty()
{
	fint a=0,b=1,c=getchar();
	while(!isdigit(c))b^=c=='-',c=getchar();
	while(isdigit(c))a=a*10+c-48,c=getchar();
	return b?a:-a;
}

const int _ = 1000007 , mo = 1000000007;

int n;
lint f[_]={0};

int main()
{
	n=ty();

	f[n]=n,f[n-1]=1ll*n*n%mo;
	flint sf=0;
	for(fint i=n-2;i>=1;i--)
	{
		sf=(sf+f[i+3])%mo;
		f[i]=(f[i+1]+(1ll*n-1)*(1ll*n-1)%mo+sf+i+1)%mo;
	}
	printf("%lld\n",f[1]);
	return 0;
}
