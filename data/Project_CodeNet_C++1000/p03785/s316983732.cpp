
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





int main() {
	ll N,C,K;
	cin >> N >> C >> K;
	ll an = 1;
	
	vector<ll> A(N);
	
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		
	}
	sort(A.begin(), A.end());
	ll t = A.at(0);
	ll ni = 1;
	for (int i = 1; i < N; i++) {
		if (ni < C && A.at(i) - t <= K) {
			ni++;
		}
		else {
			t = A.at(i);
			ni = 1;
			an++;
		}
	}
	cout << an << endl;
}

