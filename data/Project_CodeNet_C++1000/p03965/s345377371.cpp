#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	string s; cin >> s;
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			ans += s[i] == 'g';
		}
		else {
			ans -= s[i] == 'p';
		}
	}
	cout << ans << endl;
	return 0;
}
