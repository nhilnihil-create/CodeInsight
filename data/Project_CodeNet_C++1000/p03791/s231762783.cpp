#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; scanf("%d", &n); std::vector<int> x(n);
	for(int i = 0; i < n; i++) scanf("%d", &x[i]);

	// solve
	i64 ans = 1, cnt = 0;
	const int MOD = 1e9 + 7;
	for(int i = 0; i < n; i++) {
		if(cnt * 2 < x[i]) {
			cnt++;
		} else {
			(ans *= cnt + 1) %= MOD;
		}
	}
	while(cnt) (ans *= cnt--) %= MOD;
	
	printf("%lld\n", ans);
	return 0;
}
