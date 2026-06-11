#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime> 
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int alr = 0;
	int alr_b = 0;
	for (auto c : s) {
		int ok = 1;
		ok = ((c == 'a' && alr < a + b) || (c == 'b' && alr < a + b && alr_b < b));
		if (ok) {
			alr++;
			if (c == 'b') alr_b++;
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}