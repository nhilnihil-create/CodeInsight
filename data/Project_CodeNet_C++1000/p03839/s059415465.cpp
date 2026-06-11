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
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::vector<int> ac(n+1,0); // all
	std::vector<int> bc(n+1,0); // plus only
	rep(i,n) ac[i+1] = ac[i] + a[i];
	rep(i,n) bc[i+1] = bc[i] + std::max(0ll,a[i]);
	debug(ac,bc);
	int max = 0;
	for(int l=0;l+k<=n;l++) {
		int r = l+k;
		int sum = bc[n]-bc[r] + bc[l]; // white
		max = std::max(max, sum);
		sum += ac[r] - ac[l]; // black
		max = std::max(max, sum);
	}
	print(max);

	return 0;
}
