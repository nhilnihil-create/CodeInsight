//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,a[100111];
ll tot,dp[100111];
vector<int> con[100111];
void dfs(int x,int pre=-1)
{
//	cerr<<"dfs:"<<x<<endl;
	if(con[x].size()==1)
	{
		dp[x]=a[x];
		return;
	}
	ll st=0;
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		dfs(con[x][i],x);
		dp[x]+=dp[con[x][i]];
	}
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		st=max(st,2*dp[con[x][i]]-dp[x]);
	}
	
	if(a[x]>dp[x])
	{
		puts("NO");
		exit(0);
	}
	ll comb=dp[x]-a[x];
	if(2*comb>dp[x]-st)
	{
		puts("NO");
		exit(0);
	}
	dp[x]-=2*comb;
//	cerr<<x<<":"<<dp[x]<<endl;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
	if(n==1)
	{
		puts("YES");
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2])puts("YES");
		else puts("NO");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(con[i].size()==1)
		{
			tot+=a[i];
		}
	}
	if(tot&1)
	{
		puts("NO");
		return 0;
	}
	tot/=2;
	int rt=1;
	while(con[rt].size()==1)rt++;
	dfs(rt);
	if(dp[rt]==0)puts("YES");
	else puts("NO");
	return 0;
}