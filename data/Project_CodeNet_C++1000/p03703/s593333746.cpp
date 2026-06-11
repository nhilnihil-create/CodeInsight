#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
const long long INF = (long long) 1e18;

int n, k;
long long s[N], fw[N];

void compress() {
	vector <long long> zip; zip.push_back(-INF);
	for (int i = 0; i <= n; i++) {
		zip.push_back(s[i] - 1LL * i * k);
	}
	sort(zip.begin(), zip.end());
	zip.resize(distance(zip.begin(), unique(zip.begin(), zip.end())));
	for (int i = 0; i <= n; i++) {
		s[i] = lower_bound(zip.begin(), zip.end(), s[i] - 1LL * i * k) - zip.begin();
	}
}

void upd (int i) {
	for (; i <= n + 1; i += i & -i) fw[i]++;
}

long long get(int i) {
	long long res = 0;
	for (; i >= 1; i -= i & -i) res += fw[i];
	return res;
}

int main() {
	//freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int v; scanf("%d", &v);
		s[i] = s[i - 1] + v;
	}
	compress();
	long long ans = 0;
	upd(s[0]);
	for (int i = 1; i <= n; i++) {
		ans += get(s[i]);
		upd(s[i]);
	}
	printf("%lld\n", ans);
	return 0;
}