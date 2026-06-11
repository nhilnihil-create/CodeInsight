#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n;
int x[N];
pair<int,int> a[N];
int res[N * N];
int rem[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) rem[i] = n;
	for (int i = 1; i <= n; ++i) cin >> x[i], a[i] = make_pair(x[i], i);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i) if (a[i].first == a[i - 1].first) {
		printf("No\n"); return 0;
	}

	deque <int> dq;
	int ptr = 1;

	for (int pos = 1; pos <= n * n; ++pos) {
		if (a[ptr].first == pos) {
			res[pos] = a[ptr].second; --rem[a[ptr].second];
			if (dq.size() < a[ptr].second - 1) return printf("No\n"), 0;
			int cnt = 0;
			while(cnt < a[ptr].second - 1) {
				int p = dq.front(); dq.pop_front();
				res[p] = a[ptr].second;
				--rem[a[ptr].second];
				++cnt;
			}
			++ptr;
		} else {
			dq.push_back(pos);
		}
	}

	vector<int> REM;
	for (int i = 1; i <= n; ++i) {
		while(rem[a[i].second]--) {
			REM.push_back(a[i].second);
		}
	}
	reverse(REM.begin(), REM.end());

	for (int pos = 1; pos <= n * n; ++pos) {
		if (res[pos]) continue;
		res[pos] = REM.back(); REM.pop_back();
	}

	// check
	ptr = 1;
	for (int pos = 1; pos <= n * n; ++pos) {
		rem[res[pos]]++;
		if (a[ptr].first == pos) {
			if (rem[a[ptr].second] != a[ptr].second - 1) return printf("No\n"), 0;
			++ptr;
		}
	}

	// out
	printf("Yes\n");
	for (int i = 1; i <= n * n; ++i) printf("%d ", res[i]); printf("\n");
}