#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

#define dump1(v) for(auto i:v) std::cout << i << ' '; std::cout << "\n";
#define dump2(v) for(auto i:v) { for(auto j:i) std::cout << j << ' '; std::cout << "\n"; }


signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n,0);
	for(int i=1;i<n;i++) {
		std::cin >> a[i];
		a[i]--;
	}
	std::vector<std::vector<int> > from(n,std::vector<int>());

	for(int to=1;to<n;to++) {
		from[a[to]].emplace_back(to);
	}

	std::function<int(int)> dfs = [&] (int i) -> int {
		if(from[i].size()==0) return 1;
		std::vector<int> depth;
		for(int to:from[i]) {
			depth.emplace_back(dfs(to));
		}
		int max = 0;
		std::sort(all(depth),std::greater<int>());
		for(int j=0;j<from[i].size();j++) {
			max = std::max(max,depth[j]+j);
		}
		return max+1;
	};

	print(dfs(0)-1);

	
	return 0;
}
