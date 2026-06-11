#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

#define lowbit(x) (x&(-x))
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e7;
const int maxn = 3e5 + 5;
ll mod = 1e9 + 7;

int n;
ll a[maxn], b[maxn], cnt[maxn],idx[maxn], ans[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
		++cnt[a[i]];
		if (!idx[a[i]]) idx[a[i]] = i;
		else idx[a[i]] = MIN(idx[a[i]], i);
	}
	
	int cur = 100000, nxt;
	while (cur && !cnt[cur]) cur--;
	while (cur)
	{
		nxt = cur - 1;
		while (nxt && !cnt[nxt]) --nxt;

		ans[idx[cur]] += cnt[cur] * (b[cur] - b[nxt]);
		cnt[nxt] += cnt[cur];
		idx[nxt] = MIN(idx[nxt], idx[cur]);
		cur = nxt;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", ans[i]);
	}
}