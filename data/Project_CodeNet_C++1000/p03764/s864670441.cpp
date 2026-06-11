#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
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
	i64 n, m; scanf("%lld%lld", &n, &m);
	std::vector<i64> x(n), y(m);
	for(int i = 0; i < n; i++) scanf("%lld", &x[i]);
	for(int i = 0; i < m; i++) scanf("%lld", &y[i]);

	i64 A = 0, B = 0;
	const int MOD = 1e9 + 7;
	for(i64 i = 0; i < n; i++) (A += x[i] * i - x[i] * (n - i - 1)) %= MOD;
	for(i64 i = 0; i < m; i++) (B += y[i] * i - y[i] * (m - i - 1)) %= MOD;
	printf("%lld\n", A * B % MOD);
	return 0;
}
