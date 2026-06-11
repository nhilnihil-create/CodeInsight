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
	int a,b,c,d,e,f,g;
	std::cin >> a >> b >> c >> d >> e >> f >> g;
	if(b==0&&d<=1&&e<=1&&a<=1) {
		if(a==1&&d==1&&e==1) {
			print(3);
			return 0;
		}
		print(0);
		return 0;
	}
	int k=0;
	k+=b;
	if(a>2) {
		k+=((a-1)/2)*2;
		a-=((a-1)/2)*2;
	}
	if(d>2) {
		k+=((d-1)/2)*2;
		d-=((d-1)/2)*2;
	}
	if(e>2) {
		k+=((e-1)/2)*2;
		e-=((e-1)/2)*2;
	}
	int c2 = 0;
	if(a==2) c2++;
	if(d==2) c2++;
	if(e==2) c2++;
	if(c2==2) {
		print(k+4);
		return 0;
	}
	if(c2==3) {
		print(k+6);
		return 0;
	}
	if(a>0&&d>0&&e>0) {
		print(k+3);
		return 0;
	}
	if(c2==1) {
		print(k+2);
		return 0;
	}
	print(k);

	return 0;
}
