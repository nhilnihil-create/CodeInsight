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
	int n,l;
	std::cin >> n >> l;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	rep(i,n-1) {
		if(a[i]+a[i+1]>=l) {
			print("Possible");
			rep(j,i) print(j+1);
			for(int j=n-2;j>i;j--) print(j+1);
			print(i+1);
			return 0;
		}
	}
	print("Impossible");
	return 0;
}
