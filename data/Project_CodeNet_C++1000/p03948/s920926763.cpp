#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
signed main() {
	int n, t; cin >> n >> t;
	int k = 0, m = 10000000000, p = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (i) {
			if (a - m == p)k++;
			else if (a - m > p) {
				p = a - m;
				k = 1;
			}
		}
		m = min(a, m);
	}
	cout << k << endl;
}