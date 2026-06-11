#include <bits/stdc++.h>

typedef int64_t s64;
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

bool ok(int n, int *a) {
	int ch = 0;
	for (int i = 0; i < n; i++) ch = std::max(ch, a[i]);
	std::multiset<int> as;
	for (int i = 0; i < n; i++) as.insert(a[i]);
	as.erase(ch);
	if (ch % 2) {
		int half = (ch + 1) / 2;
		for (int i = half; i < ch; i++) {
			if (as.count(i) < 2) return false;
			as.erase(as.find(i));
			as.erase(as.find(i));
		}
		for (auto i : as) if (i <= half) return false;
	} else {
		if (!as.count(ch / 2)) return false;
		as.erase(as.find(ch / 2));
		for (int i = ch / 2 + 1; i < ch; i++) {
			if (as.count(i) < 2) return false;
			as.erase(as.find(i));
			as.erase(as.find(i));
		}
		for (auto i : as) if (i <= ch / 2) return false;
	}
	return true;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	
	std::cout << (ok(n, a) ? "Possible" : "Impossible") << std::endl;
	return 0;
}
