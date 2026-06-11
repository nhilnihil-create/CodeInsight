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

int n,val[_],stk[_]={0},top=0,xl[_],xr[_];

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty(),xl[i]=1,xr[i]=n;

	top=0,stk[top]=0;
	for(int i=1;i<=n;i++)
	{
		while(top && val[stk[top]]>val[i])top--;
		xl[i]=stk[top]+1,stk[++top]=i;
	}
	top=0,stk[top]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top && val[stk[top]]>val[i])top--;
		xr[i]=stk[top]-1,stk[++top]=i;
	}

	lint ans=0;
	for(int i=1;i<=n;i++)ans=ans+1ll*val[i]*(i-xl[i]+1)*(xr[i]-i+1);
	printf("%lld\n",ans);

	return 0;
}
