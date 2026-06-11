#include <cstdio>
#include <algorithm>

using namespace std;

namespace io
{
	const int maxb = 1 << 15;
	char b[maxb], *s = b, *t = b;
	bool Getchar(char &ch)
	{
		return ch = s == t && (t = (s = b) + fread(b, 1, maxb, stdin)) == b ? 0 : *s ++;
	}
}

int Getint()
{
	using namespace io;
	char ch;
	while (Getchar(ch) && (ch < '0' || ch > '9'));
	int s = ch - '0';
	while (Getchar(ch) && ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0';
	return s;
}

const int maxn = 1e5 + 10;

int x[maxn];

int main()
{
	int N = Getint(), L = Getint(), T = Getint();
	int t = T / L;
	T %= L;
	int sa = Getint(), sw = Getint();
	int sx = x[0] = sw & 1 ? (sa + T) % L : (sa + L - T) % L;
	int del = 0;
	if (sw & 1)
	{
		for (int i = 1; i < N; ++ i)
		{
			int a = Getint(), w = Getint();
			x[i] = w & 1 ? (a + T) % L : (a + L - T) % L;
			if (w == sw) continue;
			a -= sa;
			del += T * 2 > a;
			del += T * 2 > a + L;
			del += 2 * t;
		}
	}
	else
	{
		for (int i = 1; i < N; ++ i)
		{
			int a = Getint(), w = Getint();
			x[i] = w & 1 ? (a + T) % L : (a + L - T) % L;
			if (w == sw) continue;
			a = L - (a - sa);
			del += T * 2 >= a;
			del += T * 2 >= a + L;
			del += 2 * t;
		}
		del = -del;
	}
	sort(x, x + N);
	int pos;
	for (int i = 0; i < N; ++ i)
		if (x[i] == sx)
		{
			pos = i;
			break;
		}
	pos = ((pos - del) % N + N) % N;
	for (int i = pos; i < N; ++ i) printf("%d\n", x[i]);
	for (int i = 0; i < pos; ++ i) printf("%d\n", x[i]);
	return 0;
}
