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

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];

	std::sort(all(a));
	// check if a[i] is needed
	int l = -1, r = n;
	while(r-l>1) {
		int mid = (r+l)/2;
		int needed = false;
		// knapsack without a[i]
		std::vector<int> dp(k,0);
		dp[0] = 1;
		rep(i,n) {
			if(i==mid) continue;
			for(int v=k-1;v>0;v--) {
				if(v-a[i]>=0) dp[v] = std::max(dp[v],dp[v-a[i]]);
			}
		}
		int max = 0;
		for(int v=k-1;v>0;v--) {
			if(dp[v]>0) {
				max = v;
				break;
			}
		}
		if(max+a[mid]>=k) needed = true;
		if(needed) r=mid;
		else l=mid;
	}
	print(r);
	return 0;
}
