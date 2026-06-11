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
long long a[100010];
int main() {
	long long n, l;
	cin >> n >> l;
	long long m = l - 1, co;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (m < a[i] + a[i + 1]) {
			m = a[i] + a[i + 1];
			co = i + 1;
		}
	}
	if (m < l) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" << endl;
		for (int i = 1; i < co; i++) {
			cout << i << endl;
		}
		for (int i = n - 1; i > co; i--) {
			cout << i << endl;
		}
		cout << co << endl;
	}
}
