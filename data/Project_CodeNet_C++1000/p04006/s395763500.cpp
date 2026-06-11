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

const int _ = 2007;

int n;lint val[_],per;
lint sval=0,now[_],ans=1e18;

int main()
{
	n=ty(),per=ty();
	for(int i=0;i<n;i++)val[i]=ty(),sval+=val[i];
	ans=sval;

	for(int i=0;i<n;i++)now[i]=val[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)now[j]=min(now[j],val[(j-i+n)%n]);
		sval=per*i;
		for(int j=0;j<n;j++)sval+=now[j];
		ans=min(ans,sval);
	}
	printf("%lld\n",ans);

	return 0;
}
