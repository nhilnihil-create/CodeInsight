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
#define N 101
#define int long long
int n, m, a[N], cnt, b[N], tot, s;
signed main()
{
	read(n), read(m);
	for(int i= 1; i <= m; i++)
	{
		read(a[i]);
		if(a[i] & 1) ++cnt;
		if(cnt > 2)
		{
			printf("Impossible\n");
			return 0;
		}
	}
	if(m == 1)
	{
		print(a[1]);
		b[++tot]= a[1] - 1;
		b[++tot]= 1;
	}
	else
	{
		if(cnt == 0)
		{
			for(int i= 1; i <= m; i++) print(a[i], ' ');
			putc('\n');
			b[++tot]= a[1] + 1;
			for(int i= 2; i < m; i++) b[++tot]= a[i];
			b[++tot]= a[m] - 1;
		}
		else if(cnt == 1)
		{
			for(int i= 1; i <= m; i++)
				if(a[i] & 1)
				{
					swap(a[i], a[1]);
					break;
				}
			for(int i= 1; i <= m; i++) print(a[i], ' ');
			putc('\n');
			b[++tot]= a[1] + 1;
			for(int i= 2; i < m; i++) b[++tot]= a[i];
			b[++tot]= a[m] - 1;
		}
		else
		{
			if(m == 2)
			{
				print(a[1], ' '), print(a[2]);
				b[++tot]= a[1] + a[2];
			}
			else
			{
				bool bb= 0;
				for(int i= 1; i <= m; i++)
					if(a[i] & 1)
					{
						if(!bb)
						{
							swap(a[i], a[1]);
							bb= 1;
						}
						else
						{
							swap(a[i], a[m]);
							break;
						}
					}
				for(int i= 1; i <= m; i++) print(a[i], ' ');
				putc('\n');
				b[++tot]= a[1] + 1;
				for(int i= 2; i < m; i++) b[++tot]= a[i];
				b[++tot]= a[m] - 1;
			}
		}
	}
	for(int i= 1; i <= tot; i++)
		if(b[i] == 0) ++s;
	print(tot - s);
	for(int i= 1; i <= tot; i++)
		if(b[i]) print(b[i], ' ');
	putc('\n');
	exit;
}