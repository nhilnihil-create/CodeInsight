//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
int n,cnt;
deque<int> que;
void solve(int n)
{
	if(n==1)return;
	if(n&1)
	{
		solve(n-1);
		que.push_front(++cnt);
	}
	else
	{
		solve(n>>1);
		que.push_back(++cnt);
	}
}
main()
{
	re(n);
	++n;
	solve(n);
	printf("%lld\n",cnt*2);
	for(int i:que)printf("%lld ",i);
	for(int i=1;i<=cnt;++i)printf("%lld ",i);
}
