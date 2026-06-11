#include <iostream>
#include <numeric>
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
	int A, B;
	cin >> A >> B;
	A = (A + 11) % 13;
	B = (B + 11) % 13;
	if (A > B) {
		cout << "Alice" << endl;
	}
	else if (A < B) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Draw" << endl;
	}
	
}
