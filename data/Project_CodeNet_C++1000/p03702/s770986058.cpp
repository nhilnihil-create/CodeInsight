#include <bits/stdc++.h>
using namespace std;
						
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long

int n, a, b;
int h[(int)1e5 + 5];

bool tryit(int mid) {
	bool possible = true;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (h[i] - b * mid > 0) {
			sum += (h[i] - b * mid + (a - b - 1)) / (a - b);
		}
	}
	if (sum > mid) possible = false;
	return possible;
}

int32_t main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	IOS
 
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) cin >> h[i];
	sort(h + 1, h + n + 1);
	int l = 0, r = (int)1e9 + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (tryit(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
 
 
	return 0;
}