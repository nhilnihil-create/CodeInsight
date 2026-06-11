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
	int s[100];
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	sort(s, s + n);
	if (sum % 10 == 0) {
		for (int i = 0; i < n; i++) {
			if ((sum - s[i]) % 10 != 0) {
				cout << sum - s[i] << endl;
				return 0;
			}
		}
		sum = 0;
	}
	cout << sum << endl;
	return 0;
}
