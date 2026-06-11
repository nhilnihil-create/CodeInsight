#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int n, cnt, ans;
bool c[8];

bool ir(int n, int a, int b) {
	if (n >= a && n <= b) return 1;
	return 0;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int a[n];
	REP(i, 0, n) {
		cin >> a[i];
		if (ir(a[i], 1, 399)) c[0] = 1;
		else if (ir(a[i], 400, 799)) c[1] = 1;
		else if (ir(a[i], 800, 1199)) c[2] = 1;
		else if (ir(a[i], 1200, 1599)) c[3] = 1;
		else if (ir(a[i], 1600, 1999)) c[4] = 1;
		else if (ir(a[i], 2000, 2399)) c[5] = 1;
		else if (ir(a[i], 2400, 2799)) c[6] = 1;
		else if (ir(a[i], 2800, 3199)) c[7] = 1;
		else cnt++;
	}
	for (auto x : c) ans += x;
	cout << max(ans, 1) << " " << ans + cnt;
}
