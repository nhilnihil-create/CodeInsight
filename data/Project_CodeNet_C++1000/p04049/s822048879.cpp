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

const int _ = 2007<<1 , __ = _<<1;

int to[__],ne[__],he[_]={0},ecnt=1;
void adde(int a,int b){to[++ecnt]=b,ne[ecnt]=he[a],he[a]=ecnt;}
void addde(int a,int b){adde(a,b),adde(b,a);}

int n,nn,lim;

int dfs(int x,int ff,int d)
{
	if(d<=0)return x<=n;
	int ans=x<=n;
	for(int i=he[x];i;i=ne[i])
	{
		int b=to[i];
		if(b==ff)continue;
		ans+=dfs(b,x,d-1);
	}
	return ans;
}

int main()
{
	n=ty(),lim=ty(),nn=n+n;
	for(int i=n+1;i<nn;i++)
	{
		int a=ty(),b=ty();
		addde(a,i),addde(i,b);
	}

	int ans=0;
	for(int i=1;i<nn;i++)ans=max(ans,dfs(i,0,lim));
	printf("%d\n",n-ans);

	return 0;
}
