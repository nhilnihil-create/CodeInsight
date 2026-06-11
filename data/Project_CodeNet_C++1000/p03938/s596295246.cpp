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

const int N = 20000 , _ = N + 7;

int n,val[_],vala[_],valb[_];

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty();

	for(int i=1;i<=n;i++)vala[i]=i*N,valb[i]=(n-i+1)*N;
	for(int i=1,x;i<=n;i++)x=i/2,vala[val[i]]+=x,valb[val[i]]+=i-x;
	for(int i=1;i<=n;i++)printf("%d%c",vala[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)printf("%d%c",valb[i]," \n"[i==n]);

	return 0;
}
