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
int a[maxn],n,m,cnt;
bool cmp(int a,int b)
{
	return b<a;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;a[i++]=read());
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n+2;i++)
		if(a[i]<i)
		{
			m=i-1;
			break;
		}
	// if(a[m+1]!=m&&a[m]==m) puts("Second");
	// if(a[m+1]==m&&a[m]==m)
	// {
	// 	for(int i=m;a[i+1]==m;i++)
	// 		cnt++;
	// 	puts(cnt&1?"First":"Second");
	// }
	// if(a[m]!=m&&a[m+1]!=m) puts(a[m]-m&1?"First":"Second");
	// if(a[m]!=m&&a[m+1]==m)
	// {
	for(int i=m;a[i+1]==m;i++)
		cnt++;
	puts(cnt&1||a[m]-m&1?"First":"Second");
	// }
	return 0;
}
