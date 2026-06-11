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
	long long x, y;
	cin >> x >> y;
	x *= -1;
	long long ans = 100000000007;
	if (y >= x) {
		if (ans > y - x + 1) {
			ans = y - x + 1;
		}
	}
	y *= -1;
	if (y >= x) {
		if (ans > y - x + 2) {
			ans = y - x + 2;
		}
	}
	x *= -1;
	if (y >= x) {
		if (ans > y - x + 1) {
			ans = y - x + 1;
		}
	}
	y *= -1;
	if (y >= x) {
		if (ans > y - x) {
			ans = y - x;
		}
	}
	cout << ans << endl;
}
