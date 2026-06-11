#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20, mod = 924844033;
int n;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vi a(n);
	for(auto &i : a) cin >> i;
	vi b = a;
	sort(all(b));
	for(auto &i : a) i = lower_bound(all(b), i) - b.begin();
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if((a[i]^i)&1) ans++;
	}
	cout << ans/2;
}
