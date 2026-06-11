#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 505;
const int MAXM = 250005;

int n, cur_l = 1, cur_r = 1, cnt_l[MAXN], cnt_r[MAXN], p[MAXN], a[MAXN], b[MAXM];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read(), p[i] = i, b[a[i]] = i, cnt_l[i] = i - 1, cnt_r[i] = n - i;
	sort(p + 1, p + n + 1, [&](int x, int y) { return a[x] < a[y]; });
	for (int i = 1; i <= n * n; i ++)
		if (!b[i])
		{
			while (cur_l <= n && (a[p[cur_l]] < i || !cnt_l[p[cur_l]]))
				cur_l ++;
			if (cur_l <= n)
				b[i] = p[cur_l], cnt_l[p[cur_l]] --;
			else
			{
				while (cur_r <= n && !cnt_r[p[cur_r]])
					cur_r ++;
				if (cur_r > n || a[p[cur_r]] > i)
					return puts("No"), 0;
				b[i] = p[cur_r], cnt_r[p[cur_r]] --;
			}
		}
	puts("Yes");
	for (int i = 1; i <= n * n; i ++)
		printf("%d%c", b[i], i == n * n ? '\n' : ' ');
	return 0;
}
