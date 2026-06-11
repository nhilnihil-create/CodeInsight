#include <bits/stdc++.h>

int main() {
	long long n;
	std::cin >> n, ++n;
	std::vector<int> bit;
	std::list<int> ans;
	while (n) 
		bit.push_back(n & 1), n >>= 1;
	int cur = 0;
	for (int i = (int)(bit.size()) - 2; i >= 0; --i) {
		ans.push_back(++cur);
		if (bit[i]) ans.push_front(++cur);
	}
	for (int i = 1; i <= cur; ++i) ans.push_back(i);
	std::cout << ans.size() << std::endl;
	for (auto x : ans) std::cout << x << " ";
	std::cout << std::endl;
}
