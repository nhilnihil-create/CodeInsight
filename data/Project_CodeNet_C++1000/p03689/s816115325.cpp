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

const int MAX = 1e9-1;
signed main() {
	int H,W,h,w;
	std::cin >> H >> W >> h >> w;
	if(H%h==0 && W%w==0) {
		print("No");
		return 0;
	}
	if((H/h+W/w+1)*(MAX)<=(H/h)*(W/w)) {
		print("No");
		return 0;
	}
	print("Yes");
	std::vector<std::vector<int> > hw(h,std::vector<int>(w,0));
	hw[0][0] = MAX; hw[h-1][w-1] = -MAX-1;

	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			std::cout << hw[i%h][j%w] << ' ';
		}
		std::cout << ENDL;
	}
	return 0;
}
