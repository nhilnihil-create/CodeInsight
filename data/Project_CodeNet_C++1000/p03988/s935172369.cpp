#include <cstdio>
#include <cctype>
#include <set>
#include <iostream>

using namespace std;

typedef long long LL;

inline char gc()
{
	static const int L = 23333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt)
	{
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) return EOF;
	}
	return *sss++;
}

#ifdef ___my_computer
#define gc getchar
#endif

#define dd c = gc()
template <class T>
inline bool read(T& x)
{
	x = 0;
	register char dd;
	bool flag = false;
	for (; !isdigit(c); dd)
	{
		if(c == '-') flag = true;
		else if(c == EOF) return false;
	}
	for (; isdigit(c); dd)
		x = (x << 1) + (x << 3) + (c ^ 48);
	if (flag) x = -x;
	return true;
}
#undef dd

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int tong[maxn];

int main()
{
	int n, zj = 0;
	read(n);
	for (int i = 1, a; i <= n; ++i)
	{
		read(a);
		tong[a]++;
		zj = max(a, zj);
	}
//	cout << tong[2] << ' ' << tong[3] << endl;
//	cout << "zj = " << zj << endl;
	for (int i = 0; i <= zj; ++i)
	{
		int noww = max(i, zj - i);
//		cout << i << ' ' << noww << endl;
		if (!tong[noww])
		{
			puts("Impossible");
			return 0;
		}
		tong[noww]--;
	}
	for (int i = 1; i <= ((zj + 1) >> 1); ++i)
	{
		if (tong[i])
		{
			puts("Impossible");
			return 0;
		}
	}
//	if (zj == 2 && tong[2])
//	{
//		puts("Impossible");
//		return 0;
//	}
	puts(tong[1] ? "Impossible" : "Possible");
	return 0;
}