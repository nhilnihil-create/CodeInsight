#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 2007 , __ = _*_ , mo = 1000000007;

inline lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a)
{
	return powa(a,mo-2);
}

lint jc[__],rjc[__];

inline void fuck(int n=__-1)
{
	jc[0]=jc[1]=rjc[0]=1;
	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mo;
	rjc[n]=inva(jc[n]);
	for(int i=n-1;i>=1;i--)rjc[i]=rjc[i+1]*(1ll+i)%mo;
}

inline lint C(int n,int m)
{
	return jc[n]*rjc[m]%mo*rjc[n-m]%mo;
}

int n,m;
lint f[_][_]={0};

int main()
{//
	n=ty(),m=ty();
	if(m<=1){puts("1");return 0;}

	fuck();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>0)f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%mo*C(n*m-i-(j-1)*(m-1)-1,m-2)%mo)%mo;
		}
	}
	printf("%lld\n",f[n][n]);

	return 0;
}
