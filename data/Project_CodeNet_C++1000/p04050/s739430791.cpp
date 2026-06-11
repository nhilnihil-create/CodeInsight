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
int n,m,a[100111];
int b[100111],bn;
int main()
{
	getii(n,m);
	int cnt1=0;
	for(int i=1;i<=m;i++)geti(a[i]),cnt1+=a[i]&1;
	if(cnt1>2)
	{
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=m;i++)if(a[i]&1)
	{
		if(a[1]&1)swap(a[i],a[m]);
		else swap(a[i],a[1]);
	}
	if(m==1)
	{
		if(a[1]==1)
		{
			cout<<1<<endl<<1<<endl<<1<<endl;
			return 0;
		}
		else
		{
			cout<<a[1]<<endl;
			cout<<2<<endl;
			cout<<1<<" "<<a[1]-1<<endl;
			return 0;
		}
	}
	b[bn++]=a[1]+1;
	for(int i=2;i<m;i++)b[bn++]=a[i];
	if(a[m]!=1)b[bn++]=a[m]-1;
	for(int i=1;i<=m;i++)puti(a[i]);puts("");
	putsi(bn);
	for(int i=0;i<bn;i++)puti(b[i]);
	return 0;
}
