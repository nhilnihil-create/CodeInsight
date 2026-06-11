
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





int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> C(M);
	vector<ll> D(M);
	rep(i, N) {
		cin >> A.at(i) >> B.at(i);
	}
	rep(i, M) {
		cin >> C.at(i) >> D.at(i);
	}
	ll k = 0;
	ll d = 9999999999999999;
	rep(i, N) {
		k = -1;
		d = 9999999999999999;
		rep(j, M) {
			if (d > abs(A.at(i) - C.at(j)) + abs(B.at(i) - D.at(j))) {
				d = abs(A.at(i) - C.at(j)) + abs(B.at(i) - D.at(j));
				k = j + 1;
			}
		}
		cout <<k << endl;
	}

}