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
	int s = -1, t = -1;
	for(int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		
		a--; b--; s = a; t = b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::deque<int> ans;
	ans.push_front(s); ans.push_back(t);
	std::queue<int> qu; qu.push(s); qu.push(t);
	std::vector<bool> used(n, false); used[s] = used[t] = true;
	while(!qu.empty()) {
		auto v = qu.front(); qu.pop();

		for(auto e: g[v]) {
			if(used[e]) continue;
			if(v == ans.front()) ans.push_front(e);
			if(v == ans.back()) ans.push_back(e);
			used[e] = true;
			qu.push(e);
			break;
		}
	}

	printf("%d\n", ans.size());
	while(!ans.empty()) {
		printf("%d ", ans.front() + 1);
		ans.pop_front();
	}
	return 0;
}
