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
	int a[101000];
	int ni = 0, ans = 0, ans1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 4 == 0) {
			ans++;
		}
		else if (a[i] % 2 == 0) {
			ni++;
		}
	}
	ans1 = (ans + 1) * 2 - 1;
	if (ans == 0) {
		ans1 = 1;
	}
	if (ans1 >= n) {
		cout << "Yes" << endl;
	}
	else if (n - ans1 + 1<= ni) {
		if (ni == 1) {
			cout << "No" << endl;
			return 0;
		}
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
	