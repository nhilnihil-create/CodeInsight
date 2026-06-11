#include <iostream> // cout, endl, cin
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
#include<math.h>
#define int long long
using namespace std;
const int INF = 10000000000000;

signed main() {
	int N;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++) cin >> s[i];
	int wa = 0;
	int small = INF;
	for (int i = 0; i < N; i++) wa += s[i];
	if (wa % 10 == 0) {
		for (int i = 0; i < N; i++) {
			if (s[i] % 10 != 0 && small > s[i]) small = s[i];
		}
		if (small == INF) cout << "0" << endl;
		else cout << wa - small << endl;
	}
	else cout << wa << endl;


}