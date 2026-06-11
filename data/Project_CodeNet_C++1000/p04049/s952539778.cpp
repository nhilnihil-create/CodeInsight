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
	int n, k; scanf("%d%d", &n, &k);
	std::vector<int> a(n - 1), b(n - 1);
	std::vector<std::vector<int>> g(n);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--; b[i]--;

		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	int ans = n;
	for(int i = 0; i < n; i++) {
		auto dfs = [&](auto&& dfs, int v, int par, int d) -> int {
			int ret = d <= (k / 2);
			for(auto id: g[v]) {
				int to = a[id] ^ b[id] ^ v;
				if(to == par) continue;
				ret += dfs(dfs, to, v, d + 1);
			}
			return ret;
		};

		if(k & 1) {
			// 中心が二つ
			for(auto id: g[i]) {
				int to = a[id] ^ b[id] ^ i;
				int ret = dfs(dfs, to, i, 0) + dfs(dfs, i, to, 0);

				ans = std::min(ans, n - ret);
			}
		} else {
			int ret = dfs(dfs, i, -1, 0);
			ans = std::min(ans, n - ret);
		}
	}

	printf("%d\n", ans);
	return 0;
}
