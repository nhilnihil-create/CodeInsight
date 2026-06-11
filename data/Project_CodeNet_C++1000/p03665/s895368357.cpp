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
	long long n, p;
	long long a[100];
	cin >> n >> p;
	long long g = 1, k = 0;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			g *= 2;
		}
		else {
			k++;
		}
	}
	long long ans1 = 0;
	if (p == 0) {
		for (long long i = 0; i <= k; i += 2) {
			long long ans = 1;
			for (long long j = 0; j <= i; j++) {
				ans *= (k - j);
				ans /= (j + 1);
			}
			ans1 += ans;
		}
		if (ans1 == 0) {
			ans1 = 1;
		}
	}
	else {
		ans1 = 0;
		for (long long i = 1; i <= k; i += 2) {
			long long ans = 1;
			for (long long j = 0; j < i; j++) {
				ans *= (k - j);
				ans /= (j + 1);
			}
			ans1 += ans;
		}
	}
	cout << ans1 * g << endl;
	return 0;
}
