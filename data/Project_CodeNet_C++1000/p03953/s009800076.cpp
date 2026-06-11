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
ll K,a[100111],b[100111],nb[100111];
int t[100111],p[70][100111];
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]),b[i]=a[i]-a[i-1],t[i]=i;
	getii(m,K);
	for(int i=1;i<=m;i++)
	{
		int x;
		geti(x);
		swap(t[x],t[x+1]);
	}
	for(int i=1;i<=n;i++)p[0][t[i]]=i;
//	for(int i=1;i<=n;i++)cerr<<t[i]<<" ";cerr<<endl;
//	for(int i=1;i<=n;i++)cerr<<b[i]<<" ";cerr<<endl;
	for(int i=1;i<63;i++)for(int j=1;j<=n;j++)p[i][j]=p[i-1][p[i-1][j]];
	for(int i=62;i>=0;i--)
	{
		if((K>>i)&1)
		{
			for(int j=1;j<=n;j++)nb[p[i][j]]=b[j];
			swap(nb,b);
		}
	}
	for(int i=1;i<=n;i++)a[i]=a[i-1]+b[i],putsi(a[i]);
	return 0;
}
