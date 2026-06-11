#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 100003, M = N << 2;

int n, t, a[N];
int pre[N], suf[N];

int main()
{
	//File("");
	n = gi <int> (), t = gi <int> ();
	memset(pre, 0x3f, sizeof pre);
	memset(suf, 0, sizeof suf);
	for (int i = 1; i <= n; i+=1) a[i] = gi <int> ();
	for (int i = n; i >= 1; i-=1) suf[i] = max(suf[i + 1], a[i]);
	int mx = 0, cnt = 0;
	for (int i = 1; i <= n; i+=1) mx = max(mx, suf[i] - a[i]);
	for (int i = 1; i <= n; i+=1) if (mx == suf[i] - a[i]) ++cnt;
	printf("%d\n", cnt);
	return 0;
}
