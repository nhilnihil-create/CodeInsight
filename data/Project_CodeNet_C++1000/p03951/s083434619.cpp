
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
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}
ll Mid(ll(a), ll(b), ll(c)) {
	return a+b+c-Max(a,b,c)-Min(a,b,c);
}

int gcd(ll(a), ll(b)) {
	ll c = a;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}



int main() {
	int N;
	string s, t;
	cin >> N >> s >> t;
	
	int i = N;
	while (s.substr(N - i, i) != t.substr(0, i) &&i>0) {
		i--;
		
	}

	cout << 2*N-i << endl;
}