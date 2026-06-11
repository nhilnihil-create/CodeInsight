#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long
#define pb push_back
#define pi pair <int, int> 

int n, l[150], k;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	sort(l, l+n, greater<int>());
	for(int i = 0; i < k; ++i) {
		ans += l[i];
	}
	cout << ans;
}