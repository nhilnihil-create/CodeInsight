#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <list>
#include <cmath>
using namespace std;

int main() {
	string S;
	cin >> S;
	int n = 0;
	int w = 0;
	int s = 0;
	int e = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == 'N') {
			n++;
		} else if (S[i] == 'W') {
			w++;
		} else if (S[i] == 'S') {
			s++;
		} else if (S[i] == 'E') {
			e++;
		}
	}
	bool yes = true;
	if ((n == 0 && s != 0) || (n != 0 && s == 0)) {
		yes = false;
	}
	if ((e == 0 && w != 0) || (e != 0 && w == 0)) {
		yes = false;
	}
	if (yes) {
		cout  << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}