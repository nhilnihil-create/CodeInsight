#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5050, mlg = 17, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool can(vi a) {
	//for(auto i : a) cout << i << " "; cout << '\n';
	int n = a.size();
	int l, r; l = r = n/2;
	while(l > 0 && a[l-1] != a[l]) l--;
	while(r+1 < n && a[r+1] != a[r]) r++;
	int mid = (l+r)/2;
	//cout << l << " " << r << " = " << (n/2 <= mid ? a[l] : a[r]) << '\n';
	return n/2 <= mid ? a[l] : a[r];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	n = 2*n - 1;
	vi a(n);
	for(auto &i : a) cin >> i;
	int ans = 0;
	for(int i = 1<<18; i>>=1;) {
		vi b;
		ans += i;
		for(auto j : a) b.pb(j>=ans);
		if(!can(b)) ans -= i;
	}
	cout << ans;
}
