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
	vector<long long> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a1;
		cin >> a1;
		a.emplace_back(a1);
	}
	sort(a.begin(), a.end());
	long long sum = 0, ans = 1000000007;
	for (int i = 0; i < n-1; i++) {
		sum += a[i];
		if (sum * 2 < a[i + 1]) {
			ans = n - i - 1;
		}
	}
	if (ans == 1000000007) {
		ans = n;
	}
	cout << ans << endl;
	return 0;
}