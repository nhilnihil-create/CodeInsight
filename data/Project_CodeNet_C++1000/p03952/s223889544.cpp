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

int n,loc;

int main()
{
	n=ty(),loc=ty();
	if(n==1){puts("Yes\n1");return 0;}
	if(loc==1 || loc==n+n-1){puts("No");return 0;}
	puts("Yes");
	for(int i=n-(loc>n);i>=1;i--)if(i!=loc)printf("%d\n",i);
	printf("%d\n",loc);
	for(int i=n+n-1;i>=n+(loc<=n);i--)if(i!=loc)printf("%d\n",i);
	
	return 0;
}
