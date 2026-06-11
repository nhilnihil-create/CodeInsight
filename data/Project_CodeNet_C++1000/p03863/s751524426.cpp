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

	string s;
	cin >> s;
	int n = (int)s.size();
	int emod = 0;
	if (s.front() == s.back()) emod = 1;
	else emod = 0;
	if ((n - emod) & 1) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
}
