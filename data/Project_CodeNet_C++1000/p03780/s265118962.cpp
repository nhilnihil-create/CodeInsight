#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n, k; scanf("%d%d", &n, &k); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(begin(a), end(a));
	
	if(std::accumulate(begin(a), end(a), 0LL) < k) {
		printf("%d\n", n);
		return 0;
	}
	
	auto f = [&](int t) {
		if(a[t] >= k) return true;
		
		std::bitset<5001> dp; dp[0] = true; 
		for(int i = 0; i < n; i++) if(i != t) dp |= dp << a[i];
		for(int i = k - a[t]; i < k; i++) if(dp[i]) return true;
		return false;
	};
	
	int ok = n - 1, ng = -1;
	while(std::abs(ok - ng) > 1) {
		int mid = (ok + ng) >> 1;
		
		if(f(mid)) ok = mid;
		else ng = mid;
	}
	
	printf("%d\n", ok);
	return 0;
}
