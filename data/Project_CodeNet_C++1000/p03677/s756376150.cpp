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
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	rep(i,n) a[i]--;
	
	std::vector<int> cycle(m,0);
	rep(i,n-1) {
		int dist = ((a[i+1]-a[i])%m+m)%m;
		if(dist<=1) continue;
		if((a[i+1]+1)%m>(a[i]+2)%m) {
			cycle[(a[i]+2)%m] += 1;
			cycle[(a[i+1]+1)%m] -= dist;
			if((a[i+1]+2)%m!=0) cycle[(a[i+1]+2)%m] += dist-1;
		} else {
			cycle[(a[i]+2)%m] += 1;
			cycle[0] += m-1-a[i];
			cycle[1] -= m-2-a[i];
			cycle[(a[i+1]+1)%m] -= dist;
			if((a[i+1]+2)%m!=0) cycle[(a[i+1]+2)%m] += dist-1;
		}
	}
	rep(i,m-1) cycle[i+1] += cycle[i];
	rep(i,m-1) cycle[i+1] += cycle[i];
	int max = 0;
	rep(i,m) max = std::max(max,cycle[i]);
	int cycles = 0;
	rep(i,n-1) {
		if(((a[i+1]-a[0])%m+m)%m<((a[i]-a[0])%m+m)%m) cycles++;
	}
	int count = cycles*m+((a[n-1]-a[0])%m+m)%m;
	print(count-max);

	return 0;
}
