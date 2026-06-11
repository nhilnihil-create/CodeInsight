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

int n,val[_];

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	sort(val+1,val+n+1,greater<int>());

	int now=1;
	while(now<n && now+1<=val[now+1])now++;
	if((val[now]-now)%2==0)
	{
		int cnt=0;
		while(now+cnt<n && now-1<val[now+cnt+1])cnt++;
		if(cnt%2==0){puts("Second");return 0;}
	}
	puts("First");
	
	return 0;
}
