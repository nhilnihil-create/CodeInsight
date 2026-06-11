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
	int n;
	cin >> n;
	int a[110];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 10 != 0) {
		cout << sum << endl;
		return 0;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] % 10 != 0) {
			cout << sum - a[i] << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}

