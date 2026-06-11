#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define SZ(x) ((int)x.size())

const int N = (int)1e5+5;
const ll oo = (ll)1e18+7;
int n, op[N];
ll a[N], f[N][3];

void readData() {
	scanf("%d", &n);
	op[0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (i == n) break;
		char s[2]; scanf("%s", s);
		if (s[0] == '-') op[i] = -1;
		else op[i] = 1;
	}
}

namespace my_old_sol {
	ll dp[N], sum[N];
	priority_queue<ll> pq;
	vector<int> q;

	void solve() {
		readData();
		for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
		int idx = 1;
		for (; idx <= n; ++idx) {
			dp[idx] = sum[idx];
			if (op[idx] == -1) break;
		}
		for (int i = idx + 1; i <= n; ++i) {
			dp[i] = dp[i - 1] + (ll)op[i - 1] * a[i];
			if (op[i - 1] == -1) {
				if (SZ(q)) {
					ll val = sum[i - 1] - sum[q.back() - 1];
					pq.push(dp[q.back() - 1] - val - sum[i - 1]);
				}
				q.push_back(i);
			}
			if (SZ(pq) > 0) dp[i] = max(dp[i], pq.top() + sum[i]);
		}
		printf("%lld", dp[n]);
	}
}

int main() {
	readData();
	for (int i = 0; i <= n; ++i) f[i][0] = f[i][1] = f[i][2] = -oo;
	f[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) if (f[i][j] != -oo) {
			int oper = (j % 2 == 0 ? op[i] : -op[i]);
			f[i + 1][j] = max(f[i + 1][j], f[i][j] + (ll)oper * a[i + 1]);
			if (op[i] == -1 && j < 2) f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + (ll)oper * a[i + 1]);
			if (j > 0) f[i + 1][j - 1] = max(f[i + 1][j - 1], f[i][j] + (ll)oper * a[i + 1]);
		}
	}
	printf("%lld", max(f[n][0], max(f[n][1], f[n][2])));
	return 0;
}
