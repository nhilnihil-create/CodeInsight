#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

inline LL gl()
{
	LL f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 3003, M = N << 2;
const string s = "RYGB";

int h, w, d;

int main()
{
	h = gi(), w = gi(), d = gi();
	for (int i = 1; i <= h; i+=1)
	{
		for (int j = 1; j <= w; j+=1)
		{
			int x = i + j + w, y = i - j + w;
			cout << s[((x / d) & 1) * 2 + ((y / d) & 1)];
		}
		puts("");
	}
	return 0;
}
//