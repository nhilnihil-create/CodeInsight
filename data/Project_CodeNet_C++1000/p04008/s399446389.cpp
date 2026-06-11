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

int to[_],ne[_],he[_]={0},ecnt=1;
void adde(int a,int b){to[++ecnt]=b,ne[ecnt]=he[a],he[a]=ecnt;}

int n,lim,ans=0,nex[_],dep[_]={0};

void dfs(int x)
{
	dep[x]=1;
	for(int i=he[x];i;i=ne[i]){int b=to[i];dfs(b),dep[x]=max(dep[x],dep[b]+1);}
	if(nex[x]!=1 && dep[x]>=lim)ans++,dep[x]=0;
}

int main()
{
	n=ty(),lim=ty();
	for(int i=1;i<=n;i++)nex[i]=ty();
	if(nex[1]!=1)ans++,nex[1]=1;

	for(int i=2;i<=n;i++)adde(nex[i],i);
	dfs(1),printf("%d\n",ans);

	return 0;
}
