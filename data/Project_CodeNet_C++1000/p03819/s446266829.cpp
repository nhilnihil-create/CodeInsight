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

const int INF = 0x3f3f3f3f, N = 300003, M = N << 2;

int n, m;
int tr[N];
struct Node {int l, r, len;} x[N];
int ans[N];

inline int lowbit(int i) {return i & (-i);}

inline void add(int x, int val)
{
	for (int i = x; i <= m; i += lowbit(i)) tr[i] += val;
}

inline int getans(int x)
{
	int sum = 0;
	for (int i = x; i; i -= lowbit(i)) sum += tr[i];
	return sum;
}

inline bool cmp(Node x, Node y) {return x.len < y.len;}

int main()
{
	//File("");
	n = gi <int> (), m = gi <int> ();
	for (int i = 1; i <= n; i+=1)
		x[i].l = gi <int> (), x[i].r = gi <int> (), x[i].len = x[i].r - x[i].l + 1, add(x[i].l, 1), add(x[i].r + 1, -1);
	sort(x + 1, x + 1 + n, cmp);
	int now = n;
	for (int i = m; i >= 1; i-=1)
	{
		while (now >= 1 && x[now].len >= i)
			add(x[now].l, -1), add(x[now].r + 1, 1), --now;
		ans[i] = n - now;
		for (int j = i; j <= m; j+=i) ans[i] += getans(j);
	}
	for (int i = 1; i <= m; i+=1) printf("%d\n", ans[i]);
	return 0;
}
