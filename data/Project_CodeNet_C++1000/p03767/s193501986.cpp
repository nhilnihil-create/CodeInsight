#include<bits/stdc++.h>
using namespace std;
const int maxn = 606, mod = 119<<23|1;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(3*n);
	for(auto &i : a) cin >> i;sort(a.rbegin(), a.rend());
	long long ans = 0;
	for(int i = 0; i < n; i++) ans += a[2*i + 1];
	cout << ans;
	return 0;
}
