#include <iostream>
#include <string>
#include <algorithm>    
#include <cmath>
#include <map>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <queue>
#include <tuple>
#include <cassert>
#include <set>
#include <functional>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
int test[345678];
signed main() {
	int n, m, a = -1; cin >> n >> m;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	for (int h = 1; h < n; h++) {
		if (test[h - 1] + test[h] >= m) {
			a = h; 
		}
	}
	if (a == -1) { cout << "Impossible" << endl; }
	else {
		cout << "Possible" << endl;
		for (int h = 1; h < n; h++) {
			if (a == h) { break; }
			cout << h << endl;
		}
		for (int h = n - 1; h >= 1; h--) {
			if (a == h) { break; }
			cout << h << endl;
		}
		cout << a << endl;
	}
	return 0;
}