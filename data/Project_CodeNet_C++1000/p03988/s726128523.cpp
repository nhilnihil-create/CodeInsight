#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, d;
int a[maxn], cnt[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		d = max(d, a[i]);
	}
	int lim = (d + 1) / 2;
	int sum = 0;
	for (int i = lim + 1; i <= d; ++i) {
		sum += (cnt[i] >= 2) ? cnt[i] : -sum;
	}
	sum += (cnt[lim] == 1 + d % 2) ? cnt[lim] : -sum;
	cout << (sum == n ? "Possible" : "Impossible") << endl;
	return 0;
}
