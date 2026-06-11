#include <cstdio>
#include <algorithm>

using namespace std;

#define Fo(i, l, r) for (int i = l; i <= r; ++ i)
#define Fod(i, r, l) for (int i = r; i >= l; -- i)

typedef long long LL;

namespace io
{
	const int maxb = 1 << 15;
	char b[maxb], *s = b, *t = b;
	bool Getchar(char &ch)
	{
		return ch = s == t && (t = (s = b) + fread(b, 1, maxb, stdin)) == b ? 0 : *s ++;
	}
}

LL Getint()
{
	using namespace io;
	char ch;
	bool f = false;
	while (Getchar(ch) && (ch < '0' || ch > '9'))
		f |= ch == '-';
	LL s = ch - '0';
	while (Getchar(ch) && ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0';
	return f ? -s : s;
}

const int maxn = 1e5 + 10;

int p[maxn];
LL x[maxn], a[maxn];

void Power(int n, int *p, LL k)
{
	static int res[maxn];
	Fo(i, 1, n) res[i] = i;
	for (; k; k >>= 1)
	{
		if (k & 1) Fo(i, 1, n) res[i] = p[res[i]];
		Fo(i, 1, n) a[i] = p[p[i]];
		Fo(i, 1, n) p[i] = a[i];
	}
	Fo(i, 1, n) p[i] = res[i];
}

int main()
{
	int n = Getint();
	Fo(i, 1, n)
	{
		x[i] = Getint();
		p[i] = i;
	}
	Fod(i, n, 1) x[i] -= x[i - 1];
	int m = Getint();
	LL k = Getint();
	Fo(i, 1, m)
	{
		int pos = Getint();
		swap(p[pos], p[pos + 1]);
	}
	Power(n, p, k);
	Fo(i, 1, n) a[i] = x[p[i]];
	Fo(i, 1, n) a[i] += a[i - 1];
	Fo(i, 1, n) printf("%lld\n", a[i]);
	return 0;
}
