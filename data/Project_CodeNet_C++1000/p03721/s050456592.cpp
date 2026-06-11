#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}


ll a[100009];


int main() {
	ll N, K;
	cin >> N >> K;
	vector<pair<ll, ll>> A(N);
	rep(i, N) {
		ll a, b;
		cin >> a >> b;

		A.at(i)=make_pair(a,b);
	}
	sort(A.begin(), A.end());
	rep(i, N) {
		K -= A.at(i).second;
		if (K <= 0) {
			cout << A.at(i).first << endl;
			return 0;
		}
	}
}
