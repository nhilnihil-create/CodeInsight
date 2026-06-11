
#include <iostream>
#include <numeric>
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}

ll gcd(ll(a), ll(b)) {
	ll k = a;
	ll l = b;
	ll j = 0;
	while (l != 0) {
		j = k % l;
		k = l;
		l = j;
	}
	return k;
}



int main() {
	ll N,x;
	cin >> N>>x;
	
	vector<ll> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}
	ll an=0;
	if (vec.at(0) > x) {
		an += vec.at(0) - x;
		vec.at(0) = x;
	}
	for (int i = 1; i < N; i++) {
		if (vec.at(i - 1) + vec.at(i) > x) {
			an += vec.at(i - 1) + vec.at(i) - x;
			vec.at(i) = x - vec.at(i - 1);
		}
		
	}
	cout << an << endl;;

	
}
