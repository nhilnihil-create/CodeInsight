//waz
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))

int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

int H, W, h, w;

int t[510][510];

long long res;

int main()
{
	gii(H, W), gii(h, w);
	for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= W; ++j)
			t[i][j] = 2000;
	for (int i = h; i <= H; i += h)
		for (int j = w; j <= W; j += w)
			t[i][j] = -((h * w - 1) * 2000 + 1);
	for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= W; ++j)
			res += t[i][j];
	if (res <= 0)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
		for (int i = 1; i <= H; ++i)
			for (int j = 1; j <= W; ++j)
				printf("%d%c", t[i][j], " \n"[j == W]);
	}
	return 0;
}