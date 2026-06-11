#include <cstdio>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const int N = 1e5 + 10;
int n, K, ans, a[N], q[N], deg[N], dis[N];

template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x *= f;
}

int main() {
	int u, v, l = 0, r = 0; in(n), in(K);
	for (int i = 1; i <= n; ++i) in(a[i]), ++deg[a[i]];
	if (a[1] != 1) --deg[a[1]], a[1] = 1, ++ans;
	for (int i = 1; i <= n; ++i) if (!deg[i]) q[++r] = i;
	for (; l < r;) {
		v = a[u = q[++l]]; if (u == 1) break; 
		if (v != 1 && dis[u] == K - 1) ++ans;
		else dis[v] = max(dis[v], dis[u] + 1);
		if (!(--deg[v])) q[++r] = v;
	}
	printf("%d\n", ans);
	return 0;
}