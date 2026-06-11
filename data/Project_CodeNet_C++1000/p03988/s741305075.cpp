#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 700010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
int a[maxn],cnt[maxn];
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),++cnt[a[i]];
	int mx=0;
	for(int i=1;i<=n;i++)
		mx=std::max(mx,a[i]);
	for(int i=1;2*i<mx;i++)
		if(cnt[i]){
			puts("Impossible"); return 0;
		}
	for(int i=(mx+1)/2;i<=mx;i++)
		cnt[i]-=2;
	if(mx%2==0)++cnt[mx/2];
	if(cnt[(mx+1)/2]){
		puts("Impossible"); return 0;
	}
	for(int i=(mx+1)/2;i<=mx;i++)
		if(cnt[i]<0){
			puts("Impossible"); return 0;
		}
	puts("Possible");
	return 0;
}