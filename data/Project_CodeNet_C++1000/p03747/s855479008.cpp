// #pragma GCC optimize(3)
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100010
// #define int long long
using namespace std;
void write(int x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}
int read(){int d=0,w=1;char c=getchar();for(;c<'0'||c>'9';c=getchar())if(c=='-')
w=-1;for(;c>='0'&&c<='9';c=getchar())d=(d<<1)+(d<<3)+c-48;return d*w;}
void wln(int x){write(x);putchar('\n');}
void wrs(int x){write(x);putchar(' ');}
int n,l,t,w[maxn],x[maxn],cnt,ans[maxn],anss[maxn];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=read();
	l=read();
	t=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		w[i]=read()==1?1:-1;
		ans[i]=((x[i]+w[i]*t)%l+l)%l;
	}
	sort(ans+1,ans+n+1);
	// wrs(w[1]);
	// wrs(n-x[4]+x[1]);
	// if(w[1]==1)
	// {
	// cnt=1;
	for(int i=2;i<=n;i++)
		if(w[i]!=w[1]&&2*t>=(w[1]==1?x[i]-x[1]:l-x[i]+x[1])) cnt=(cnt+w[1]*((2*t-(w[1]==1?x[i]-x[1]:l-x[i]+x[1]))/l+1));
	cnt+=1;
	// int llk=lower_bound(ans+1,ans+n+1,((x[1]+w[1]*t)%l+l)%l)-ans;
	int llk;
	if(w[1]==1) llk=upper_bound(ans+1,ans+n+1,((x[1]+w[1]*t)%l+l)%l)-ans-1;
		else llk=lower_bound(ans+1,ans+n+1,((x[1]+w[1]*t)%l+l)%l)-ans;
	// wrs(llk);
	// wln(cnt);
	for(int i=1;i<=n;i++)
		anss[i]=ans[((llk-cnt+i)%n+n-1)%n+1];
	for(int i=1;i<=n;i++)
		wln(anss[i]);
		// ans[cnt]=(x[1]+t)%l;
		// for(int i=1;i<=n;i++)
		// 	if(w[((1-cnt+i)%n+n-1)%n+1]==1) ans[i]=(x[((1-cnt+i)%n+n-1)%n+1]+t)%l;
		// for(int i=1;i<=n;i++)
		// 	wrs(ans[i]);
	// }
	return 0;
}
