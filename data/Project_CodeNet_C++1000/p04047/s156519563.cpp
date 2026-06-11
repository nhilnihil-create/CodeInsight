#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5+7;

int32_t main() {
    IOS;
	int n;
	cin >> n;
	n = n * 2;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i+=2)
		ans += min(a[i], a[i+1]);
	cout << ans << endl;
    return 0;
}
