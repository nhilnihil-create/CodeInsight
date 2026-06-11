#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,ans,a[100005];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i)
		if(i+1>a[i+1])
		{
			for(int j=i+1;a[j]==i;++j)ans^=1;
			ans|=(a[i]-i)&1;
			if(ans)puts("First");else puts("Second");
			return 0;
		}
}