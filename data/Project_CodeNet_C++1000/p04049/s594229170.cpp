#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
template <class T> T read(T &a) {
    a=0;char x=getchar();bool f=0;
    for(;x<'0'||x>'9';x=getchar())f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())a=(a<<3)+(a<<1)+x-'0';
    if(f)a=-a;
    return a;
}
using namespace std;

const int N = 2e3 + 5;
int n, k;
int f[N], cnt = 0;
int nnext[N << 1], v[N << 1];

inline void add(int a, int b) {
	nnext[++cnt] = f[a];
	f[a] = cnt;
	v[cnt] = b;
}

int dfs(int a, int b, int c, int d) {
	int ans = 1;
	if (c > d) return 0;
	for (int i = f[a]; i; i = nnext[i]) {
		int to = v[i];
		if (to != b) {
			ans += dfs(to, a, c + 1, d);
		}
	}
	return ans;
}

int main() {
	read(n), read(k);
	for (int i = 1; i < n; ++i) {
		int a, b;
		read(a), read(b);
		add(a, b);
		add(b, a);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int tot = 0, pre = 0;
		for (int j = f[i]; j; j = nnext[j]) {
			int to = v[j];
			int a = dfs(to, i, 1, k / 2);
		    int b = dfs(to, i, 1, k - k / 2);
		    tot += a;
		    pre = max(pre, b - a);
		}
		ans = max(ans, 1 + tot + pre);
	}
	printf("%d\n", n - ans);
    return 0;
}
