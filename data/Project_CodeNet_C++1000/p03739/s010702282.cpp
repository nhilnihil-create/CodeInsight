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
int main() {
	int n;
	long long a[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (i % 2 == 0) {
			if (sum <= 0) {
				ans += abs(sum) + 1;
				sum = 1;
			}
		}
		else {
			if (sum >= 0) {
				ans += abs(sum) + 1;
				sum = -1;
			}
		}
	}
	sum = 0;
	long long ans1 = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (i % 2 == 0) {
			if (sum >= 0) {
				ans1 += abs(sum) + 1;
				sum = -1;
			}
		}
		else {
			if (sum <= 0) {
				ans1 += abs(sum) + 1;
				sum = 1;
			}
		}
	}
	if (ans > ans1) {
		cout << ans1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}