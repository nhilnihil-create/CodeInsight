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

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	if(n==1) {
		print("YES");
		return 0;
	}
	int sum=0;
	rep(i,n) sum+=a[i];
	int dd=n*(n+1)/2;
	if(sum%dd) {
		print("NO");
		return 0;
	}
	int k=sum/dd;
	std::vector<int> b(n);
	rep(i,n) {
		b[i]=a[(i+1)%n]-a[i];
		// b[i]=k-x-(n-1)*x
		if(k<b[i] || (k-b[i])%n) {
			print("NO");
			return 0;
		}
	}
	print("YES");
	return 0;
}
