#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int mn = 2e5 + 10;

long long n, ans, a[mn], l[mn], r[mn];

stack <int> sta;

int main () {
	ios::sync_with_stdio (false);
	
	cin >> n, a[0] = a[n + 1] = -inf;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sta.push (0);
	
	for (int i = 1; i <= n; i++) {
		while (a[i] <= a[sta.top ()]) sta.pop ();
		l[i] = sta.top (), sta.push (i);
	}
	
	while (!sta.empty ()) sta.pop ();
	
	sta.push (n + 1);
	
	for (int i = n; i >= 1; i--) {
		while (a[i] < a[sta.top ()]) sta.pop ();
		r[i] = sta.top (), sta.push (i);
	}
	
	for (int i = 1; i <= n; i++)
		ans += a[i] * (i - l[i]) * (r[i] - i);
		
	cout << ans;
	
	return 0;
} 