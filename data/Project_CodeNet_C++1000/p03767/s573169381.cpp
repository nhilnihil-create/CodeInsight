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
	long long N, a, ans=0, cnt=0;
	cin >> N;

	vector<long long> v(3*N, 0);

	for (size_t i = 0; i < 3*N; i++) cin >> v.at(i);

	sort(v.begin(), v.end());
	for (size_t i=N; i<v.size(); i++) {
		if (cnt%2 == 0) ans += v.at(i);
		cnt++;
	}

	cout << ans << endl;

	return 0;
}
