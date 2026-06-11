#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20, mod = 924844033;
ll n, k, a[maxn], b[maxn], c[maxn];
ll ans = 0;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) b[i] = max(a[i], 0ll) + b[i-1];
	for(int i = n; i; i--) c[i] = max(a[i], 0ll) + c[i+1];
	for(int i = 1; i <= n; i++) a[i] += a[i-1];
	for(int i = k; i <= n; i++) {
		ll t = max(0ll, a[i] - a[i-k]);
		t += b[i-k] + c[i+1];
		ans = max(ans, t);
	}
	cout << ans;
}
