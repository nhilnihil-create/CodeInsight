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
bool b[100010] = { false };
int co[100010];
int main() {
	int n, m;
	cin >> n >> m;
	b[1] = true;
	for (int i = 1; i <= n; i++) {
		co[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (b[x]) {
			if (co[x] == 1) {
				b[x] = false;
			}
			b[y] = true;
		}
		co[x]--;
		co[y]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
