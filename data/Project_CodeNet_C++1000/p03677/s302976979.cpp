#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3e5;
const int MAXM = 3e5;
int N, M;
int A[MAXN];

ll s1[MAXN];
ll s2[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i]--;
	}

	ll tot = 0;
	for (int i = 0; i < N-1; i++) {
		int cur = A[i];
		int nxt = A[i+1];
		if (cur > nxt) nxt += M;
		tot += nxt - cur;

		s1[cur+1] ++;
		s1[nxt+1] --;
		s2[cur+1] += cur;
		s2[nxt+1] -= cur;
	}
	for (int i = 1; i < 2*M; i++) {
		s1[i] += s1[i-1];
		s2[i] += s2[i-1];
	}

	ll ans = tot;
	for (int i = 0; i < M; i++) {
		ll cost = tot;
		cost -= (i-1) * s1[i] - s2[i];
		cost -= (i+M-1) * s1[i+M] - s2[i+M];
		ans = min(ans, cost);
	}
	cout << ans << '\n';

	return 0;
}
