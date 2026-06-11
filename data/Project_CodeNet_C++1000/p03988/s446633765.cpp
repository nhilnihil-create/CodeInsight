//  Christopher_Yan Move on!!!
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>

using namespace std;

inline void read(int &x)
{
	int k = 1; x = 0;
	char c = getchar();
	while (!isdigit(c)) 
		if (c == '-') c = getchar(), k = -1;
		else c = getchar();
	while (isdigit(c))
		x = (x << 1) + (x << 3) + (c ^ 48),
		c = getchar();
	x *= k;
}

int n, a[220], maxa = -11111, d[220];

signed main()
{
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]), maxa = max(a[i], maxa), ++d[a[i]];
	if (d[maxa >> 1] != 1 && !(maxa & 1))
		{ puts("Impossible"); return 0; }
	if (d[1 + (maxa >> 1)] != 2 && (maxa & 1))
		{ puts("Impossible"); return 0; }
	for (int i = 1 + (maxa >> 1); i <= maxa; ++i)
		if (d[i] < 2)
			{ puts("Impossible"); return 0; }
	for (int i = 1; i <= ((maxa >> 1) - (maxa % 2 == 0)); ++i)
		if (d[i] > 0)
			{ puts("Impossible"); return 0; }
	puts("Possible");
	return 0;
}