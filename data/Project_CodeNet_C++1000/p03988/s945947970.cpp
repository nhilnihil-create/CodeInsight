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
	if(0) {
possible:
		print("Possible");
		return 0;
impossible:
		print("Impossible");
		return 0;
	}
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];

	int k = 0;
	for(int e:a) k=std::max(k,e);

	std::multiset<int> set(all(a));

	std::vector<int> necessary;
	for(int i=0;i<=k/2;i++) {
		int x = i; int y = k-i;
		auto it = set.find(k-i);
		if(it==set.end()) goto impossible;
		set.erase(it);
		if(x==y) break;
		it = set.find(k-i);
		if(it==set.end()) goto impossible;
		set.erase(it);
	}

	int l = (k+1)/2+1;
	int r = k;

	for(int e:set) {
		if(e<l || r<e) goto impossible;
	}


	goto possible;


	return 0;
}
