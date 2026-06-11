#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n, l, t; scanf("%d%d%d", &n, &l, &t);
	std::vector<int> latte;
	int malta = 0;
	while(n--) {
		int a, b; scanf("%d%d", &a, &b);
		
		if(b == 1) {
			malta -= (t - (l - a) + l) / l;
			latte.push_back((a + t) % l);
		} else {
			malta += (t - (a + 1) + l) / l;
			latte.push_back((a - t % l + l) % l);
		}
	}
	malta = (malta % (int)latte.size() + (int)latte.size()) % latte.size();
	sort(begin(latte), end(latte));
	
	for(int i = 0; i < latte.size(); i++) printf("%d\n", latte[(i - malta + (int)latte.size()) % latte.size()]);
	return 0;
}
