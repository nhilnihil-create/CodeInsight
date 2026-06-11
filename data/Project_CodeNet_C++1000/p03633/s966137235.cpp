#include <iostream>
#include <string>
#include <algorithm>
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
#define int long long
long long gcd(long long a, long long b) {
	if (a % b == 0) {
		return (b);
	}
	else {
		return (gcd(b, a % b));
	}
}
signed main() {
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		ans = ans / gcd(ans, t) * t;
	}
	cout << ans << endl;
	return 0;
}
