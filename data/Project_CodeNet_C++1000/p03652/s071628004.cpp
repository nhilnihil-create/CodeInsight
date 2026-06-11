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
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > a(n,std::vector<int> (m));
	rep(i,n) rep(j,m) std::cin >> a[i][j];

	int min = 999;
	std::set<int> set;
	rep(i,m) set.emplace(i+1);
	rep(i,m) {
		std::vector<std::vector<int> > b(n,std::vector<int>());
		rep(x,n) rep(y,m) if(set.count(a[x][y])) b[x].emplace_back(a[x][y]);
		std::map<int,int> map;
		rep(i,n) map[b[i][0]]++;
		int max = 0;
		int maxi = 0;
		for(auto x:map) if(max<x.second) {
			max=x.second;
			maxi=x.first;
		}
		min = std::min(min,max);
		set.erase(maxi);
	}
	print(min);
	return 0;
}
