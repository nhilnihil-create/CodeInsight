#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int Maxn = 2 * 100000 + 100;
int N, root;
LL A[Maxn];
int deg[Maxn];
int Begin[Maxn], To[Maxn], Next[Maxn], e;
int fa[Maxn];

inline void add_edge (int x, int y)
{
	To[++e] = y;
	Next[e] = Begin[x];
	Begin[x] = e;
}

inline void dfs (int x)
{
	int fl = 0;
	for (int i = Begin[x]; i; i = Next[i])
	{
		int y = To[i];
		if (y == fa[x]) continue;
		fl = 1;
		fa[y] = x;
		dfs(y);
	}
	if (!fl) return ;
	LL Max = -0x3f3f3f3f3f3f3f, Sum = 0ll;
	for (int i = Begin[x]; i; i = Next[i])
	{
		int y = To[i];
		if (y == fa[x]) continue;
		Sum += A[y];
		Max = max (Max, A[y]);
	}
	if (A[x] > Sum || (Sum - A[x] > min(Sum / 2, Sum - Max)))
	{
		puts("NO");
		exit(0);
	}
	A[x] -= (Sum - A[x]);
}

int main()
{
#ifdef hk_cnyali
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i < N; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
		deg[y] ++, deg[x] ++;
	}
	if (N == 2)
	{
		if (A[1] == A[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for (int i = 1; i <= N; ++i) if (deg[i] > 1){root = i; break;}
	dfs(root);
	if (!A[root]) puts("YES");
	else puts("NO");
	return 0;
}