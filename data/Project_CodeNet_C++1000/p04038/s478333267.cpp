#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,k,ans,dp[2001][2001],a[4000001],b[4000001],mod=1e9+7;
inline int read()
{
    int sum=0,x=1;
    char ch=getchar();
    while (!isdigit(ch))
	{
        if (ch=='-')
		  x=-1;
        ch=getchar();
    }
    while (isdigit(ch))
	{
        sum=(sum<<1)+(sum<<3)+(ch^'0');
        ch=getchar();
    }
    return sum*x;
}
inline void write(int x)
{
    if (x<0)
	{
        putchar('-');
        x=-x;
    }  
    if (x>9)
      write(x/10);
    putchar(x%10+'0');
}
inline int sr(int x,int y)
{
    if (y>x)
	  return 0;
    return a[x]*b[y]%mod*b[x-y]%mod;
}
inline int power(int x,int y)
{
    int s=1;
    for (;y;y>>=1,x=x*x%mod)
      if (y&1)
		s=s*x%mod;
    return s;
}
signed main()
{
    n=read();k=read();
    if (k<2)
    {
        write(1);
        return 0;
    }
    a[0]=b[0]=1;
    for (register int i=1;i<=n*k;++i)
    {
    	a[i]=a[i-1]*i%mod;
		b[i]=power(a[i],mod-2);
	}
    dp[0][0]=1;
    for (register int i=1;i<=n;++i)
      for (register int j=i;j>=0;--j)
        dp[i][j]=(dp[i][j]+dp[i-1][j-1]*sr(k*i-j-1,k-2)+dp[i][j+1])%mod;
    write(dp[n][0]*a[n]%mod);
    return 0;
}