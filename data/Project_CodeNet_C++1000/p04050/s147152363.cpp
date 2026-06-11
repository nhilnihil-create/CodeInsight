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

inline void failure(){puts("Impossible");exit(0);}

const int _ = 103;

int n,m,val[_];
vector<int> ans;

int main()
{
	n=ty(),m=ty();
	for(int i=1;i<=m;i++)val[i]=ty();

	int cnt=0;
	for(int i=1;i<=m;i++)cnt+=val[i]&1;
	if(cnt>2)failure();

	for(int i=2;i<=m;i++)
	{
		if(!(val[i]&1))continue;
		if(val[1]&1)swap(val[i],val[m]);
		else swap(val[i],val[1]);
	}

	if(m==1)
	{
		ans.emplace_back(1);
		if(val[1]>1)ans.emplace_back(val[1]-1);
	}
	else
	{
		ans.emplace_back(val[1]+1);
		for(int i=2;i<m;i++)ans.emplace_back(val[i]);
		if(val[m]>1)ans.emplace_back(val[m]-1);
	}

	for(int i=1;i<=m;i++)printf("%d%c",val[i]," \n"[i==m]);
	printf("%lu\n",ans.size());
	for(auto i:ans)printf("%d ",i);
	puts("");

	return 0;
}
