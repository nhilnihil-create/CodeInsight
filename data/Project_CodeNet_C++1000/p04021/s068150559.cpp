#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
int a[maxn],rk[maxn];
int n;
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),rk[i]=i;
	std::sort(rk+1,rk+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=std::abs(i-rk[i])&1;
	writeln(ans/2);
	return 0;
}