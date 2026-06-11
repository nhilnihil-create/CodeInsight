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

const int _ = 103;
const char *YES = "Possible" , *NO = "Impossible";

int n,val[_],cnt[_]={0};

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty(),cnt[val[i]]++;
	sort(val+1,val+n+1);

	int mi=val[1],mx=val[n];
	if(mi!=(mx+1)/2){puts(NO);return 0;}
	if(cnt[mi]!=1+(mx&1)){puts(NO);return 0;}
	for(int i=mi+1;i<=mx;i++)if(cnt[i]<2){puts(NO);return 0;}
	puts(YES);

	return 0;
}
