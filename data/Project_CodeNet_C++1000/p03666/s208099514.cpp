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
	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	b -= a;
	for (int i = 0; i < n; i++) {
		long long l = ((n - 1) - i) * c - i * d;
		long long r = ((n - 1) - i) * d - i * c;
		if (l <= b && r >= b) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
