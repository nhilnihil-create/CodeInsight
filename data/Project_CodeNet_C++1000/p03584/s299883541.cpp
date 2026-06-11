#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
#define fi first
#define se second

int n, k;
pair<int,int> a[N];
long long ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;

	for (int b = 30; b >= 0; --b) {
		int kk = ((k >> b) & 1);
		sort(a + 1, a + n + 1);

		int s1 = n + 1;
		while(s1 >= 2 && (a[s1 - 1].fi >> b & 1)) --s1;

		if (kk == 1) {
			long long sum = 0;
			for (int i = 1; i < s1; ++i) sum += a[i].se;
			for (int i = s1; i <= n; ++i) a[i].fi -= (1LL << b);
			ans = max(ans, sum);
		} else n = s1 - 1;
	}

	long long sum = 0; for (int i = 1; i <= n; ++i) sum += a[i].se;
	ans = max(ans, sum);

	cout << ans << endl;
}