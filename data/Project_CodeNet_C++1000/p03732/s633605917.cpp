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
	ll N,W;
	cin >> N >> W;
	vector<ll> w0;
	vector<ll> w1;
	vector<ll> w2;
	vector<ll> w3;
	ll wf,v0;
	cin >> wf>>v0;
	w0.push_back(v0);
	rep(i, N-1) {
		ll w, v;
		cin >> w>> v;
		if(w==wf)w0.push_back(v);
		else if (w == wf+1)w1.push_back(v);
		else if (w == wf+2)w2.push_back(v);
		else if (w == wf+3)w3.push_back(v);
	}
	ll an = 0;
	sort(w0.begin(), w0.end());
	sort(w1.begin(), w1.end());
	sort(w2.begin(), w2.end());
	sort(w3.begin(), w3.end());
	reverse(w0.begin(), w0.end());
	reverse(w1.begin(), w1.end());
	reverse(w2.begin(), w2.end());
	reverse(w3.begin(), w3.end());
	for(ll i0 = 0; i0 <= w0.size(); i0++) {
		for (ll i1 = 0; i1 <= w1.size(); i1++) {
			for (ll i2 = 0; i2 <= w2.size(); i2++) {
				for (ll i3 = 0; i3 <= w3.size(); i3++) {
					if (wf * i0 + (wf + 1) * i1 + (wf + 2) * i2 + (wf + 3) * i3 > W)continue;
					ll k = 0;
					rep(i, i0) {
						k += w0[i];
					}
					rep(i, i1) {
						k += w1[i];
					}
					rep(i, i2) {
						k += w2[i];
					}
					rep(i, i3) {
						k += w3[i];
					}
					an = max(an, k);
				}
			}
		}
	}
	cout << an << endl;
}