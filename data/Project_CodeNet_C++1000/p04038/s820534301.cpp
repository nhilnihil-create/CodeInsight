#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const long long Mod=1000000007;
int n,k;
long long fac[4000010],inv[4000010],f[2010][2010],s[2010];
long long pw(long long x,long long y)
{
	long long res=1;
	while (y)
	{
		if (y&1)
		{
			res=res*x%Mod;
		} 
		y>>=1;
		x=x*x%Mod;
	}
	return res;
}
long long c(int n,int m)
{
	if (n<m)
	{
		return 0;
	}
	return fac[n]*inv[n-m]%Mod*inv[m]%Mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	if (k==1)
	{
		puts("1");
		return 0;
	}
	fac[0]=1;
	for (int i=1;i<=n*k;i++)
	{
		fac[i]=fac[i-1]*i%Mod;
	}
	inv[n*k]=pw(fac[n*k],Mod-2);
	for (int i=n*k-1;i>=0;i--)
	{
		inv[i]=inv[i+1]*(i+1)%Mod;
	}
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		s[n+1]=0;
		for (int j=n;j>=0;j--)
		{
			s[j]=(s[j+1]+f[i-1][j])%Mod;
		}
		for (int j=1;j<=i;j++)
		{
			f[i][j]=s[j-1]*c(i*k-j-1,k-2)%Mod;
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		ans=(ans+f[n][i])%Mod;
	}
	ans=ans*fac[n]%Mod;
	printf("%lld\n",ans);
    return 0;
}
//花开堪折直须折，莫待无花空折枝。
//——《金缕衣》