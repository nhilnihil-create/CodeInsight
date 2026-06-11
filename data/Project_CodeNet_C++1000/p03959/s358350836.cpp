#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int a[345678], b[345678], high[345678];
signed main() {
	int n, ans = 1; cin >> n;
	for (int h = 1; h <= n; h++) { cin >> a[h]; }
	for (int h = 1; h <= n; h++) { cin >> b[h]; }
	for (int h = 1; h <= n; h++) {
		if (a[h - 1] < a[h]) { high[h] = a[h]; }
	}
	for (int h = n; h > 0; h--) {
		if (b[h] > b[h + 1]) {
			if (high[h] != 0 && high[h] != b[h]) { cout << 0 << endl; return 0; }
			if (b[h] > a[h]) { cout << 0 << endl; return 0; }
			high[h] = b[h];
		}
	}
	for (int h = 1; h <= n; h++) {
		if (high[h] == 0) {
			ans *= min(a[h], b[h]); ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}