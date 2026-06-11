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

const int _ = 200007;

int n,loc[_],nex[_]={0};

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)loc[ty()]=i;

	lint ans=0;
	for(int i=n;i>=1;i--)
	{
		int x=loc[i],l=nex[x-1],r=nex[x+1];
		if(!l)l=x;
		if(!r)r=x;
		ans+=1ll*i*(x-l+1)*(r-x+1),nex[l]=r,nex[r]=l;
	}
	
	printf("%lld\n",ans);

	return 0;
}
