#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

namespace io
{
	const int maxb = 1<< 15;
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

int a[maxn];

int main()
{
	int n = Getint();
	for (int i = 1; i <= n; ++ i)
		a[i] = Getint();
	sort(a + 1, a + n + 1, greater<int>());
	int pos = 0;
	while (a[pos + 1] >= pos + 1) ++ pos;
	int r = pos;
	while (a[r + 1] == pos) ++ r;
	if (a[pos] - pos & 1 || r - pos & 1) puts("First"); else puts("Second");
	return 0;
}
