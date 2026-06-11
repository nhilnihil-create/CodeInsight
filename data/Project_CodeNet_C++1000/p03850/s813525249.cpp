#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define SZ(x) ((int)x.size())

const int N = (int)1e5+5;
int n, op[N];
ll a[N], sum[N], dp[N];
priority_queue<ll> pq;
vector<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		if (i == n) break;
		char s[2]; scanf("%s", s);
		if (s[0] == '-') op[i] = -1;
		else op[i] = 1;
	}
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
	return 0;
}
