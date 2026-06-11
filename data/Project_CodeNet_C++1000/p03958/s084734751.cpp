#include <iostream>
#include <numeric>
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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)




int main() {
	int K,T;
	cin >> K>>T;
	vector<int> vec(T);
	int mm = 0;
	for (int i = 0; i < T; i++) {
		cin >> vec.at(i);
		mm = max(mm, vec.at(i));
	}
	if (mm < (K+1)/2) {
		cout << 0 << endl;
	}
	else if (K % 2 == 0) {
		cout << (2*mm - K -1) << endl;
	}
	else {
		cout << (2 * mm - K - 1) << endl;
	}
}