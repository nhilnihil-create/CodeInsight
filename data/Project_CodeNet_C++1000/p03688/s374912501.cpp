#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

bool solve(int n, int *a) {
	int min = *std::min_element(a, a + n);
	int max = *std::max_element(a, a + n);
	if (max - min > 1) return false;
	if (max == min) return min <= n / 2 || min == n - 1;
	int min_cnt = std::count(a, a + n, min);
	int max_cnt = n - min_cnt;
	if (max_cnt == 1) return false;
	return max >= min_cnt + 1 && max <= min_cnt + max_cnt / 2;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	std::cout << (solve(n, a) ? "Yes" : "No") << std::endl;
	
	return 0;
}

