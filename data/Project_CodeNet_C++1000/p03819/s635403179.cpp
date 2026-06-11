#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
 
#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)
#define RepG(i, x) for (int i = head[x]; i; i = edge[i].next)
#define v edge[i].to
#define mp(a, b) make_pair(a, b)
 
using namespace std;

const int N = 300100;

struct Seg{ int l, r;} s[N];
bool cmp(Seg a, Seg b) { return a.r - a.l < b.r - b.l;}

int tg[N];
void modify(int x, int l, int r, int a, int b)
{
	if (a <= l && r <= b){ tg[x] ++; return; }
	int mid = (l + r) >> 1;
	if (a <= mid) modify(x << 1, l, mid, a, b);
	if (b > mid) modify(x << 1 | 1, mid + 1, r, a, b);
}
int query(int x, int l, int r, int a)
{
	if (l == r) return tg[x];
	int ret = tg[x], mid = (l + r) >> 1;
	if (a <= mid) ret += query(x << 1, l, mid, a);
	else ret += query(x << 1 | 1, mid + 1, r, a);
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	Rep(i, m) scanf("%d%d", &s[i].l, &s[i].r);
	
	sort(s + 1, s + 1 + m, cmp);
	
	int t = 1;
	Rep(i, n) {
		while (t <= m && s[t].r - s[t].l + 1 <= i) {
			modify(1, 1, n, s[t].l, s[t].r);
			t ++;
		}
		int ans = m - t + 1;
		for (int j = i; j <= n; j += i) ans += query(1, 1, n, j);
		
		printf("%d\n", ans); 
	}
	
	return 0;
}