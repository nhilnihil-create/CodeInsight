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
	int a, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 != 0) {
			ans++;
		}
	}
	if (ans % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}