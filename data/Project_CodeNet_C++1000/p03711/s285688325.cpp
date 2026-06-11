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
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)






int main() {
	int x,a;
	cin >>x>>a;
	string s = "No";
	if (x == 4 || x == 6 || x == 9 || x == 11) {
		x = 1;
	}
	else if (x==2) {
	}
	else {
		x = 0;
	}
	
	if (a == 4 || a == 6 || a == 9 || a == 11) {
		a = 1;
	}
	else if (a == 2) {
	}
	else {
		a = 0;
	}

	if (x == a) {
		s = "Yes";
	}
	cout <<s<< endl;
}
