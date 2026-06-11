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

// 0-indexed
// componenet_size(k): return the size of the component which include k
class union_find_tree {
	std::vector<int> data;

	public:
	union_find_tree(const size_t && N)
		: data(N, -1) {}
	const bool unite(size_t x, size_t y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		if(data[x] > data[y]) std::swap(x, y);
		
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	const size_t find(size_t k) {
		if(data[k] < 0) return k;
		return data[k] = find(data[k]);
	}
	const size_t component_size(const size_t && k) {
		return -data[find(k)];
	}
	const bool same(const size_t && x, const size_t && y) {
		return find(x) == find(y);
	}
	
	void clear() { data.assign(size(), -1); }
	const size_t size() const { return data.size(); }
};

int main() {
	int h, w; scanf("%d%d", &h, &w); h++; w++; std::vector<int> p(h - 1), q(w - 1);
	for(int i = 0; i < h - 1; i++) scanf("%d", &p[i]);
	for(int i = 0; i < w - 1; i++) scanf("%d", &q[i]);
	
	std::vector<std::pair<int, std::pair<int, int>>> vec;
	for(int i = 0; i < h - 1; i++) vec.push_back({p[i], {i, 0}});
	for(int i = 0; i < w - 1; i++) vec.push_back({q[i], {i, 1}});
	sort(begin(vec), end(vec));

	i64 ans = 0, a = h, b = w;
	union_find_tree A(h), B(w);
	for(auto elm: vec) {
		i64 val = elm.first, id = elm.second.first, d = elm.second.second;
		
		if(d == 0) {
			A.unite(id, id + 1);
			ans += val * b;
			a--;
		} else {
			B.unite(id, id + 1);
			ans += val * a;
			b--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
