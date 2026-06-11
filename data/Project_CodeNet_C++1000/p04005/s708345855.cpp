#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <memory>        // unique_ptr, shared_ptr, weak_ptr
#include <cstring>
#include <cmath>

using namespace std;

using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;

#define _LIBCPP_DEBUG 0
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
	long long a, b, c, cube1=0, cube2=0;
	cin >> a >> b >> c;

	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
		cout << 0 << endl;
	} else if (max(a, max(b, c)) == a) {
		cube1 = (a/2+1) * b * c;
		cube2 = (a/2) * b * c;
		cout << cube1 - cube2 << endl;
	} else if (max(a, max(b, c)) == b) {
		cube1 = a * (b/2+1) * c;
		cube2 = a * (b/2) * c;
		cout << cube1 - cube2 << endl;
	} else if (max(a, max(b, c)) == c) {
		cube1 = a * b * (c/2+1);
		cube2 = a * b * (c/2);
		cout << cube1 - cube2 << endl;
	}

	return 0;
}
