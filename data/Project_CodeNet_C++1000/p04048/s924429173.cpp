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
long long n, x, a, b, ans;
signed main()
{
	read(n), read(x);
	ans= n, a= x, b= n - x;
	while(1)
	{
		if(a < b) swap(a, b);
		if(a % b == 0)
		{
			ans+= a * 2 - b;
			break;
		}
		else
		{
			ans+= a / b * 2 * b;
			a%= b;
		}
	}
	print(ans);
	exit;
}