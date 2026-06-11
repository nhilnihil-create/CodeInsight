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
int a[10010];
int main() {
	int k, t;
	cin >> k >> t;
	int ans = 0;
	for (int i = 0; i < t; i++) {
		cin >> a[i];
		ans += max(0, a[i] - k + a[i] - 1);
	}
	cout << ans << endl;

}