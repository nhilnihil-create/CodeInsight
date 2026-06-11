#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int A[MAXN], n;

void quit(int x) {
	puts(x ? "First" : "Second");
	exit(0);
}

void dfs(int w) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (~A[i] & 1) ++cnt;
	if (cnt & 1) quit(w);
	if (cnt == 0 || cnt + 2 <= n) quit(w ^ 1);
	for (int i = 1; i <= n; i++) if (A[i] & 1) cnt = i;
	if (A[cnt] == 1) quit(w ^ 1);
	int g = 0; --A[cnt];
	for (int i = 1; i <= n; i++) g = __gcd(g, A[i]);
	for (int i = 1; i <= n; i++) A[i] /= g;
	dfs(w ^ 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", A + i);
	dfs(1);
	return 0;
}