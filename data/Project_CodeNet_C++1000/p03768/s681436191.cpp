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
	int n, m; scanf("%d%d", &n, &m);
	std::vector<std::vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int q; scanf("%d", &q);
	std::vector<int> v(q), d(q), c(q);
	for(int i = 0; i < q; i++) scanf("%d%d%d", &v[i], &d[i], &c[i]);
	
	std::vector<int> ans(n, 0), used(n, -1);
	while(q--) {
		int V = v[q] - 1, D = d[q], C = c[q];
		
		std::queue<std::pair<int, int>> qu; qu.push({V, D});
		while(!qu.empty()) {
			auto p = qu.front(); qu.pop();
			
			if(p.second <= used[p.first]) continue; used[p.first] = p.second;
			if(!ans[p.first]) ans[p.first] = C;
			if(!p.second) continue;
			for(auto e: g[p.first]) {
				qu.push({e, p.second - 1});
			}
		}
	}
	
	for(auto v: ans) printf("%d\n", v);
	return 0;
}
