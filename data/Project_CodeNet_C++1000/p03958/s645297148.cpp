#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[1234][1234];
signed main() {
	ll n = 0, k, a, cnt = 0, ans = 0; cin >> n >> k;
	for (int h = 0; h < k; h++) {
		cin >> a; cnt = max(cnt, a);
	}
	cout << max((ll)0, cnt - (n - cnt) - 1) << endl;
	cin >> n; return 0;
}