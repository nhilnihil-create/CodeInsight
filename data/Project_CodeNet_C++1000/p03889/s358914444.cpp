#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)

#define rep(i,n) for(int i = 0; i < n; i++)
#define ENDL "\n"
#define print(i) std::cout << (i) << "\n"

#define int long long // at least int64 > 9*10^18
#define all(v) v.begin(), v.end()

signed main() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	if(n&1) {
		print("No");
		return 0;
	}
	std::map<char,char> map;
	map['b'] = 'd';
	map['d'] = 'b';
	map['p'] = 'q';
	map['q'] = 'p';
	for(int i=0;i<n/2;i++) {
		if(map[s[i]]!=s[n-1-i]) {print("No");return 0;}
	}
	print("Yes");
	return 0;
}
