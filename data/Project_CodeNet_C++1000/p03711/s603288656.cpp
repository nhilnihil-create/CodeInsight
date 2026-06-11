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
		int x, y; cin >> x >> y;
		if (x == 2 || y == 2) cout << "No" << endl;
		else if ((x == 4 || x == 6 || x == 9 || x == 11) && (y == 4 || y == 6 || y == 9 || y == 11)) cout << "Yes" << endl;
		else if ((x != 4 && x != 6 && x != 9 && x != 11) && (y != 4 && y != 6 && y != 9 && y != 11)) cout << "Yes" << endl;
		else cout << "No" << endl;

		return 0;
	}
