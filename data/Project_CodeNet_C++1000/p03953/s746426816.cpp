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
	
	inline lint ty()
	{
		lint a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 100007;

int n,m,who[_],nex[_],ed[_]={0},stk[_],top;
lint loc[_],chaf[_]={0},anschaf[_]={0},tim;

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)loc[i]=ty();
	m=ty(),tim=ty();
	for(int i=1;i<=m;i++)who[i]=ty();

	for(int i=1;i<=n;i++)nex[i]=i,chaf[i]=loc[i]-loc[i-1];
	for(int i=1;i<=m;i++)swap(nex[who[i]],nex[who[i]+1]);
	for(int i=1;i<=n;i++)
	{
		if(ed[i])continue;
		top=0;
		for(int x=i;!ed[x];x=nex[x])stk[top++]=x,ed[x]=1;
		for(int j=0;j<top;j++)anschaf[stk[j]]=chaf[stk[(j+tim)%top]];
	}

	for(int i=2;i<=n;i++)anschaf[i]+=anschaf[i-1];
	for(int i=1;i<=n;i++)printf("%lld.0\n",anschaf[i]);

	return 0;
}
