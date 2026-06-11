#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	long long ans = LLONG_MAX;
	for (int bit = 0;bit < (1 << n);bit++) {

		long long max = a[0];
		long long tmp = 0;
		int count = 1;
		for (int i = 1;i < n;i++) {
			if (bit & (1 << i)) {
				if (max >= a[i]) {
					tmp += max + 1 - a[i];
					max++;
				}
				count++;
			}
			if (max < a[i]) {
				max = a[i];
			}
		}

		if (count >= k) {
			if (ans > tmp) ans = tmp;
		}
	}

	cout << ans << endl;
	return 0;
}
