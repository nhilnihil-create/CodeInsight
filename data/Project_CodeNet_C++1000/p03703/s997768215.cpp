#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int k = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri() - k;
	int64_t sum[n + 1];
	sum[0] = 0;
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
	std::set<int64_t> all;
	for (int i = 0; i <= n; i++) all.insert(sum[i]);
	int cnt = 0;
	std::map<int64_t, int> compress;
	std::vector<int64_t> decompress;
	for (auto i : all) compress[i] = cnt++, decompress.push_back(i);
	int cnt2 = 1;
	while (cnt2 < cnt) cnt2 *= 2;
	std::vector<int> data;
	data.resize(2 * cnt2);
	int64_t ans = 0;
	for (int i = 1; i <= n; i++) {
		int cur = compress[sum[i - 1]] + cnt2;
		for (; cur; cur >>= 1) data[cur]++;
		
		int l = 0;
		int r = compress[sum[i]] + 1;
		int res = 0;
		for (l += cnt2, r += cnt2; l < r; l >>= 1, r >>= 1) {
			if (r & 1) r--, res += data[r];
			if (l & 1) res += data[l], l++;
		}
		ans += res;
	}
	std::cout << ans << std::endl;
	
	
	return 0;
}
