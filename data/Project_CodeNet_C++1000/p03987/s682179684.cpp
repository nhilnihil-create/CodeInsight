#pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20;
int n, a[maxn], l[maxn], r[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n+1] = -1;
	{
		vi s {0};
		for(int i = 1; i <= n; i++) {
			while(a[s.back()] > a[i]) s.pop_back();
			l[i] = s.back();
			s.push_back(i);
		}
	}
	{
		vi s {n+1};
		for(int i = n; i; i--) {
			while(a[s.back()] > a[i]) s.pop_back();
			r[i] = s.back();
			s.push_back(i);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += (r[i]-i)*1l*(i-l[i])*1ll*a[i];
	cout << ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
