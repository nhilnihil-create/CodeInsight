#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
namespace io
{
#define SIZ (1 << 21 | 1)
#define gc() (io::iS == io::iT ? (io::iT= (io::iS= io::ibuff) + fread(io::ibuff, 1, SIZ, stdin), (io::iS == io::iT ? EOF : *io::iS++)) : *io::iS++)
#define putc(x) (io::oS == io::oT ? (fwrite(io::obuff, 1, io::oS - io::obuff, stdout), io::oS= io::obuff, (*io::oS++= x)) : *io::oS++= x)
#define exit                                          \
	fwrite(io::obuff, 1, io::oS - io::obuff, stdout); \
	return 0;
	char *iS, *iT, ibuff[SIZ], obuff[SIZ], *oS= obuff, *oT= oS + SIZ - 1, fu[110], c;
	int fr;
	template <class Type>
	inline void read(Type &x)
	{
		x= 0;
		Type y= 1;
		for(c= gc(); (c > '9' || c < '0') && c != '-'; c= gc())
			;
		c == '-' ? y= -1 : x= (c & 15);
		for(c= gc(); c >= '0' && c <= '9'; c= gc()) x= x * 10 + (c & 15);
		x*= y;
	}
	inline void reads(char *x)
	{
		for(c= gc(); c == ' ' || c == '\n'; c= gc())
			;
		for(; c != ' ' && c != '\n' && c != EOF; *x= c, c= gc(), ++x)
			;
	}
	template <class Type>
	inline void print(Type x, char text= '\n')
	{
		if(x < 0) putc('-'), x*= -1;
		if(x == 0) putc('0');
		while(x) fu[++fr]= x % 10 + '0', x/= 10;
		while(fr) putc(fu[fr--]);
		putc(text);
	}
	inline void prints(char *x, char *y= NULL, char text= '\n')
	{
		for(; *x && x != y; ++x) putc(*x);
		putc(text);
	}
}  // namespace io
using io::print;
using io::prints;
using io::read;
using io::reads;
#define N 2001
int n, k, head[N], cnt, dis[N], ans= 2147483647;
struct Edge
{
	int a, b;
} e[N << 1];
inline void add(int a, int b) { e[++cnt].a= head[a], e[cnt].b= b, head[a]= cnt; }
inline void dfs(int x, int y, int z)
{
	dis[x]= dis[y] + 1;
	for(int i= head[x]; i; i= e[i].a)
	{
		if(e[i].b == y || e[i].b == z) continue;
		dfs(e[i].b, x, z);
	}
}
signed main()
{
	read(n), read(k);
	for(int i= 1, a, b; i < n; i++) read(a), read(b), add(a, b), add(b, a);
	dis[0]= -1;
	if(k & 1)
	{
		for(int i= 1; i < n; i++)
		{
			int a= e[(i << 1) - 1].b, b= e[i << 1].b;
			dfs(a, 0, b), dfs(b, 0, a);
			int x= 0;
			for(int j= 1; j <= n; j++)
				if(dis[j] > (k >> 1)) ++x;
			ans= min(ans, x);
		}
	}
	else
	{
		for(int i= 1; i <= n; i++)
		{
			dfs(i, 0, 0);
			int x= 0;
			for(int j= 1; j <= n; j++)
				if(dis[j] > (k >> 1)) ++x;
			ans= min(ans, x);
		}
	}
	print(ans);
	exit;
}