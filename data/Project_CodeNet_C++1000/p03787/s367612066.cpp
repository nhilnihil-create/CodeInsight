#include <bits/stdc++.h>

typedef long long LL;

#define FOR(i, a, b) for (int i = (a), i##_END_ = (b); i <= i##_END_; i++)
#define DNF(i, a, b) for (int i = (a), i##_END_ = (b); i >= i##_END_; i--)

template <typename Tp> void in(Tp &x) {
	char ch = getchar(), f = 1; x = 0;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') ch = getchar(), f = -1;
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}

template <typename Tp> Tp Max(const Tp &x, const Tp &y) {return x > y ? x : y;}
template <typename Tp> Tp Min(const Tp &x, const Tp &y) {return x < y ? x : y;}
template <typename Tp> bool chkmax(Tp &x, Tp y) {return x >= y ? 0 : (x=y, 1);}
template <typename Tp> bool chkmin(Tp &x, Tp y) {return x <= y ? 0 : (x=y, 1);}

const int MAXN = 1000010;

int n, m;
int cnt, head[MAXN], data[MAXN << 1], nxt[MAXN << 1], sta[MAXN];
int fa[MAXN];
bool is[MAXN];

int find(int x)
{
	int tmp = x, pre;
	while (tmp != fa[tmp]) tmp = fa[tmp];
	while (x != tmp) pre = fa[x], fa[x] = tmp, x = pre;
	return tmp;
}

void merge(int x, int y)
{
	fa[find(x)] =find(y);
}

void dfs(int now, int tmp)
{
	sta[now] = tmp;
	for (int i = head[now]; i != -1; i = nxt[i]) {
		if (!sta[data[i]]) dfs(data[i], tmp == 1 ? 2 : 1);
		else if (sta[data[i]] == sta[now]) is[find(now)] = true;
	}
}

void add(int x, int y)
{
	nxt[cnt] = head[x]; data[cnt] = y; head[x] = cnt++;
	nxt[cnt] = head[y]; data[cnt] = x; head[y] = cnt++;
}

int sz1, szj, szo, sz[MAXN];

int main()
{
	memset(head, -1, sizeof head);
	
	in(n); in(m);
	FOR(i, 1, n) fa[i] = i;

	FOR(i, 1, m) {
		int u, v; in(u); in(v); add(u, v); merge(u, v);
	}

	FOR(i, 1, n) if (!sta[i]) dfs(i, 1);

	FOR(i, 1, n) sz[find(i)]++;

	int sum = 0;
	
	FOR(i, 1, n) if (find(i) == i) {
		sum += sz[i];
		if (is[i]) szj++;
		else if (sz[i] == 1) sz1++;
		else szo++;
	}

	LL ans = 0;
	ans += 1ll * sz1 * (sum - sz1) * 2 + 1ll * sz1 * sz1;
	ans += 1ll * szj * szo * 2 + 1ll * szj * szj;
	ans += 1ll * szo * szo * 2;

	printf("%lld\n", ans);

	return 0;
}
