#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20, mod = 924844033;
int n, a[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[i]/2;
		a[i] &= 1;
		if(a[i] && a[i+1]) ans++, a[i]--, a[i+1]--;
	}
	cout << ans;
}
