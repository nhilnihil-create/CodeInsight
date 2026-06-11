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
int gcd(int a, int b) {
	if (a % b == 0) {
		return (b);
	}
	else {
		return (gcd(b, a % b));
	}
}
int main() {
	int n, k;
	int a[100010];
	cin >> n >> k;
	if (n == 1) {
		cin >> a[0];
		if (a[0] == k) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = gcd(a[0], a[1]);
	for (int j = 2; j < n; j++) {
		ans = gcd(a[j], ans);
	}
	if (k % ans == 0) {
		if (a[n - 1] < k) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
		}
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}