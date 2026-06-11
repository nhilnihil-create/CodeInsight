#pragma GCC optimize("unroll-loops,Ofast")
#pragma GCC target("avx,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll ans = 1ll<<60;
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for(auto &i : a) cin >> i, sum += i;
	ll t= 0;
	a.pop_back();
	for(auto &i : a) {
		t += i;
		sum -= i;
		ans = min(ans, abs(sum-t));
	}
	cout << ans;
	return 0;
}
