#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int main() {
	int h, w;
	int n, co = 0, co1 = 0, co2 = 0;
	bool bo = false;
	int a[10010];
	int c[100][100];
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (;;) {
		for (int j = 0; j < w; j++) {
			c[co2][j] = co1 + 1;
			co++;
			if (co == a[co1]) {
				if (co1 == n - 1) {
					bo = true;
					break;
				}
				co1++;
				co = 0;
			}
		}
		co2++;
		if (bo == true) {
			break;
		}
		for (int k = w - 1; k >= 0; k--) {
			c[co2][k] = co1 + 1;
			co++;
			if (co == a[co1]) {
				if (co1 == n - 1) {
					bo = true;
					break;
				}
				co1++;
				co = 0;
			}
		}
		if (bo == true) {
			break;
		}
		co2++;
	}
	for (int d = 0; d < h; d++) {
		for (int e = 0; e < w; e++) {
			cout << c[d][e];
			if (e != w - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
	