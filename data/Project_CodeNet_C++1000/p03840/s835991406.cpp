#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	int i, o, j, l, v;
	cin >> i >> o >> v >> j >> l >> v >> v;
	if (i >= 2) {
		int k = i % 2 + 2;
		o += i - k;
		i = k;
	}
	if (j >= 2) {
		int k = j % 2 + 2;
		o += j - k;
		j = k;
	}
	if (l >= 2) {
		int k = l % 2 + 2;
		o += l - k;
		l = k;
	}
	int p = 0;
	for (int a = 0; a <= 3; a++) {
		for (int b = 0; b <= 1; b++) {
			for (int c = 0; c <= 1; c++) {
				for (int d = 0; d <= 1; d++) {
					if (a + b * 2 <= i && a + c * 2 <= j && a + d * 2 <= l) {
						p = max(p, a * 3 + b * 2 + c * 2 + d * 2);
					}
				}
			}
		}
	}
	cout << o + p << endl;
}