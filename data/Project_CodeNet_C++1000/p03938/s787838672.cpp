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

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	rep(i,n) std::cin >> p[i];
	std::reverse(all(p));
	// take ac later
	std::vector<int> ad(n,0),bd(n,0);

	int cnt = 0;
	for(int x:p) {
		cnt++; x--;
		if(x!=0) bd[x-1]+=cnt;
		if(x!=n-1) ad[x+1]+=cnt;
	}
	debug(ad,bd);
	rep(i,n-1) ad[i+1]+=ad[i];
	rep(i,n-1) bd[n-i-2]+=bd[n-i-1];
	rep(i,n) {
		std::cout << ad[i]+i+1 << ' ';
	} std::cout << ENDL;
	rep(i,n) {
		std::cout << bd[i]+n-i << ' ';
	} std::cout << ENDL;

	return 0;
}
