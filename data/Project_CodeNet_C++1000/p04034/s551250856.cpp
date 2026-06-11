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
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i) {
		cin >> x.at(i) >> y.at(i);
	}
	map<int, int> kazu;
	map<int, bool> aka;
	for (int i = 1; i <= n; ++i) {
		kazu[i] = 1;
	}
	aka[1] = true;
	for (int i = 2; i <= n; ++i) {
		aka[i] = false;
	}
	for (int i = 0; i < m; ++i) {
		kazu[x.at(i)]--;
		kazu[y.at(i)]++;
		if (aka[x.at(i)]) {
			aka[y.at(i)] = true;
			if (kazu[x.at(i)] == 0) {
				aka[x.at(i)] = false;
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (aka.at(i)) {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}