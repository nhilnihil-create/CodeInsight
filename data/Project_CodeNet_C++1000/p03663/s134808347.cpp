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

mt19937 rng(10);

#define int long long

#ifdef LOCAL
int n;
#endif

int query(int N) {
	#ifdef LOCAL
	assert(N <= 1e18);
	if (n <= N && to_string(n) <= to_string(N)) return 1;
	if (n > N && to_string(n) > to_string(N)) return 1;
	return 0;
	#else 
	cout << "? " << N << endl;
	char c;
	cin >> c;
	return c == 'Y';
	#endif	
}

int chpref(int N) {
	while (N <= 1e17) {
		N = 10 * N + 9;
	}
	return query(N);
}

void run() {
	int pr = 0;
	for (int j = 0; j < 20; j++) {
		if (j > 0 && chpref(10 * pr + 0)) {
			if (query(pr + 1) == chpref(pr + 1)) break;
		}
		int l = 0;
		if (j > 0) l = -1;
		int r = 9;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (!chpref(10 * pr + m)) l = m;
			else r = m;
		}
		pr = 10 * pr + r;
	}
	#ifdef LOCAL
	if (n != pr) {
		cerr << "WA: " << n << endl;
		cerr << pr << endl;
		exit(0);
	} else {
		cerr << "AC" << endl;
	}
	#else 
	cout << "! " << pr << endl;
	#endif
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	#ifdef LOCAL
	while (true) {
		n = rng() % (int)(1e9) + 1;
		run();		
	}
	#else 
	run();
	#endif
}
