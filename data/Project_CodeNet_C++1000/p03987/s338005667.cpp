#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

template <typename T>
std::vector<int> sort_indexes(const std::vector<T> &v) {
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});
  return idx;
}


signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::set<int> set;
	auto idx=sort_indexes(a);
	set.emplace(-1);
	set.emplace(n);
	int ans=0;
	rep(i,n) {
		auto x=set.emplace(idx[i]).first;
		ans+=(*x-*std::prev(x))*(*std::next(x)-*x)*a[idx[i]];
	}
	print(ans);
	return 0;
}
