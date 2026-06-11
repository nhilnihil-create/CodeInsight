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

const int _ = 100007 , __ = _<<1 , inf = 0x3f3f3f3f;

int n,nn,val[__];

inline int able(int lim)
{
	int adis=inf,bdis=inf;
	for(int i=1;i<nn;i++)
	{
		if(val[i]<lim && val[i+1]<lim)adis=min(adis,min(abs(n-i),abs(n-i-1)));
		if(val[i]>=lim && val[i+1]>=lim)bdis=min(bdis,min(abs(n-i),abs(n-i-1)));
	}

	if(adis==inf && bdis==inf)return val[1]>=lim;
	return bdis<adis;
}

int main()
{
	n=ty(),nn=n+n-1;
	for(int i=1;i<=nn;i++)val[i]=ty();
	
	int l=1,r=nn;
	while(r>l)
	{
		int mid=(l+r+1)>>1;
		if(able(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);

	return 0;
}
