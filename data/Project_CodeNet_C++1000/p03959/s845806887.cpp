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
#include <cctype>
using namespace std;
long long t[100010], a[100010];
long long y[100010] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (t[n - 1] != a[0]) {
		cout << "0" << endl;
		return 0;
	}
	
	y[0] = t[0];
	y[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		if (t[i - 1] != t[i]) {
			if (a[i - 1] != a[i]) {
				cout << "0" << endl;
				return 0;
			}
			if (y[i] != 0 && y[i] != t[i]) {
				cout << "0" << endl;
				return 0;
			}
			y[i] = t[i];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (a[i - 1] != a[i]) {
			if (t[i-1] != t[i]) {
				cout << "0" << endl;
				return 0;
			}
			if (y[i - 1] != 0 && y[i - 1] != a[i - 1]) {
				cout << "0" << endl;
				return 0;
			}
			y[i - 1] = a[i - 1];
		}
	}
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (y[i] == 0) {
			ans = ans * min(a[i], t[i]) % 1000000007;
		}
		else if (y[i] > min(a[i], t[i])) {
			cout << "0" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
