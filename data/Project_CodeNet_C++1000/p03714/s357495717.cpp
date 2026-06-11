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
#define dump(...)
#endif

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(3*n);
	rep(i,3*n) std::cin >> a[i];
	std::vector<int> ldp(n+1);
	int lsum = 0;
	{
		std::priority_queue<int,std::vector<int>, std::greater<int>> que;
		rep(i,n) {
			lsum+=a[i];
			que.emplace(a[i]);
		}
		ldp[0] = lsum;
		for(int i=1;i<=n;i++) {
			que.emplace(a[n-1+i]);
			lsum += a[n-1+i];
			lsum -= que.top();
			que.pop();
			ldp[i] = lsum;
		}
	}

	std::vector<int> rdp(n+1);
	int rsum = 0;
	{
		std::priority_queue<int> que;
		rep(i,n) {
			rsum+=a[2*n+i];
			que.emplace(a[2*n+i]);
		}
		rdp[n] = rsum;
		for(int i=1;i<=n;i++) {
			que.emplace(a[2*n-i]);
			rsum += a[2*n-i];
			rsum -= que.top();
			que.pop();
			rdp[n-i] = rsum;
		}
	}

	dump(ldp,rdp);
	const int INF = 1e15;
	int max = -INF;
	rep(i,n+1) {
		max = std::max(max,ldp[i]-rdp[i]);
	}
	print(max);
	return 0;
}
