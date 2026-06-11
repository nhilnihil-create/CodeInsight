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
	ll H, W, an = 1e11 + 7;
	cin >> H >> W;
	for (ll i = 1; i < H ; i++) {
		ll s1 = i * W;
		ll s2h = ((H - i) / 2)*W;
		ll s3h = H * W - s1 - s2h;
		an = min(an, Max(s1, s2h, s3h) - Min(s1, s2h, s3h));
		ll s2w = (H - i) * (W / 2);
		ll s3w= H * W - s1 - s2w;
		an = min(an, Max(s1, s2w, s3w) - Min(s1, s2w, s3w));
	}
	swap(H, W);
	for (ll i = 1; i < H; i++) {
		ll s1 = i * W;
		ll s2h = ((H - i) / 2) * W;
		ll s3h = H * W - s1 - s2h;
		an = min(an, Max(s1, s2h, s3h) - Min(s1, s2h, s3h));
		ll s2w = (H - i) * (W / 2);
		ll s3w = H * W - s1 - s2w;
		an = min(an, Max(s1, s2w, s3w) - Min(s1, s2w, s3w));
	}
	cout << an << endl;
}
