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
int n,m;
vector<int>con[100111];
bool f[100111];
int col[100111];
bool dfs(int x,int c=2)
{
	bool ret=1;
	col[x]=c;
	for(int i=0;i<con[x].size();i++)
	{
		if(col[con[x][i]]!=0)
		{
			if(col[con[x][i]]!=(c^1))ret=0;
			continue;
		}
		if(!dfs(con[x][i],c^1))ret=0;
	}
	return ret;
}
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
		f[x]=f[y]=1;
	}
	ll ans=0;
	int useless=0;
	for(int i=1;i<=n;i++)useless+=!f[i];
	int bi=0,nbi=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]&&!col[i])
		{
			int type=dfs(i);
			if(type==1)bi++;else nbi++;
		}
	}
//	cout<<useless<<" "<<bi<<" "<<nbi<<endl;
	ans+=1ll*n*useless*2-1ll*useless*useless;
	n-=useless;
	ans+=1ll*bi*bi*2+2ll*nbi*bi+1ll*nbi*nbi;
	cout<<ans<<endl;
	return 0;
}