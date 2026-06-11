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

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];

	std::map<int,int> map;
	rep(i,n) map[a[i]]++;

	if(map.size()>2) {
		print("No");
		return 0;
	}
	if(map.size()==2) {
		auto x = *map.begin();
		auto y = *map.rbegin();
		if(x.first>=x.second && x.first+1<=x.second+y.second/2 && x.first+1==y.first && x.first+1<n) {
			print("Yes");
		} else {
			print("No");
		}
		return 0;
	}
	auto x = *map.begin();
	if(x.first+1==n || x.first*2<=n) {
		print("Yes");
	} else {
		print("No");
	}

	return 0;
}
