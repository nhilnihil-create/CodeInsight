#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	bool f = false;
	while(true) {
		int tmp = 0, beet = 0, mi = 1 << 30;
		for(auto v : a) tmp ^= (v - 1) % 2;
		for(auto v : a) beet += v % 2;
		for(auto v : a) mi = std::min(mi, v);
		if(mi == 1) {
			if(f) tmp = !tmp;
			if(!tmp) printf("Second\n");
			else printf("First\n");
			break;
		}
		if(tmp) {
			if(f) printf("Second\n");
			else printf("First\n");
			break;
		} else {
			if(beet > 1) {
				if(!f) printf("Second\n");
				else printf("First\n");
				break;
			}
		}
		for(auto &v : a) if(v % 2) v--;
		int g = a.front();
		for(auto v : a) g = std::__gcd(g, v);
		for(auto &v : a) v /= g;
		f = !f;
	}
	return 0;
}
