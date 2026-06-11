#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MP make_pair
#define Debug(x) cerr << #x << ": " << x << endl;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 3e5 + 5;

int M, N; int c[MAXN];

vector<pair<int, int>> v[MAXN];

inline int lowbit(int x) { return x & -x; }
inline void Modify(int x, int y) { for (int i = x; i <= N; i += lowbit(i)) c[i] += y; }
inline int Query(int x) { int ret = 0; for (int i = x; i; i -= lowbit(i)) ret += c[i]; return ret; }

int main() {
	M = read(); N = read();
	for (int i = 1; i <= M; i++) {
		int l = read(), r = read();
		v[r - l + 1].push_back(MP(l, r));
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (auto now : v[i]) {
			int l = now.first, r = now.second;
			Modify(l, 1); Modify(r + 1, -1); cnt++;
		}
		int ans = M - cnt;
		for (int j = i; j <= N; j += i) ans += Query(j);
		printf("%d\n", ans);
	}
	return 0;
}
