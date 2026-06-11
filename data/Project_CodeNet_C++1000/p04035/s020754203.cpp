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

const int _ = 100007;

inline void failure(){puts("Impossible");exit(0);}

int n;
lint lim,val[_]={0};

int main()
{
	n=ty(),lim=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	for(int i=1;i<n;i++)
	{
		if(val[i]+val[i+1]<lim)continue;
		puts("Possible");
		for(int j=1;j<i;j++)printf("%d\n",j);
		for(int j=n-1;j>=i;j--)printf("%d\n",j);
		return 0;
	}
	failure();

	return 0;
}
