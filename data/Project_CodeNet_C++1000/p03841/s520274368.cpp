#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ctime>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)
#define RepG(i, x) for (int i = head[x]; i; i = edge[i].next)
#define v edge[i].to
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long LL;
const int N = 510000;

pair<int, int> x[N];
int st[N], top, ans[N], q[N], l, r;

int main()
{
	int n;
	scanf("%d", &n);
	Rep(i, n){
		scanf("%d", &x[i].first);
		x[i].second = i;
	}
	sort(x + 1, x + 1 + n);
	Rep(i, n){
		for (int j = x[i - 1].first + 1; j < x[i].first; j ++) q[++ r] = j;
		ans[x[i].first] = x[i].second;
		Rep(j, x[i].second - 1) {
			if (l == r) { printf("No\n"); return 0;}
			ans[q[++ l]] = x[i].second;
		}
	}

	x[n + 1].first = n * n + 1;
	Rep(i, n + 1){
		for (int j = x[i - 1].first + 1; j < x[i].first; j ++)
			if (!ans[j]) {
				if (!top) { printf("No\n"); return 0;}
				else ans[j] = st[top --];
			}
		Rep(j, n - x[i].second) st[++ top] = x[i].second;
	}
	printf("Yes\n");
	Rep(i, n * n) printf("%d ", ans[i]);
	printf("\n");
	
	return 0;
}
/*
5
1 11 9 17 20
*/