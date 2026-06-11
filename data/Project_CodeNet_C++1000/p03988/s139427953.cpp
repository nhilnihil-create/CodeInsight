#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n);
	std::vector<int> a(n), vec(n + 1, 0);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		vec[a[i]]++;
	}
	sort(begin(a), end(a));
	
	bool f = true;
	if(a.back() % 2) {
		if(a.front() * 2 != a.back() + 1) f = false;
		if(vec[a.front()] != 2) f = false;
		
		for(int i = a.front() + 1; i <= a.back(); i++) {
			if(vec[i] > 1) continue;
			f = false;
			break;
		}
	} else {
		if(a.front() * 2 != a.back()) f = false;	
		if(vec[a.front()] != 1) f = false;
		
		for(int i = a.front() + 1; i <= a.back(); i++) {
			if(vec[i] > 1) continue;
			f = false;
			break;
		}
	}
	
	if(f) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
