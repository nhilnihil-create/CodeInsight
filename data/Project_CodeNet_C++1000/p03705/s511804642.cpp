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
	long long n, a, b;
	cin >> n >> a >> b;
	if (n == 1) {
		if (a != b) {
			cout << "0" << endl;
			return 0;
		}
	}
	if (a == b) {
		cout << "1" << endl;
		return 0;
	}
	if (a > b) {
		cout << "0" << endl;
		return 0;
	}
	else {
		cout << (n - 2) * b - (n - 2) * a + 1 << endl;
		return 0;
	}
}