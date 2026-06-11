#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
using namespace std;

int n, i;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
      
	deque<ll> ans;
	if (n % 2) {
		ans.pb(a[i]);
		i++;
	}
	while (i < n) {
		ans.pb(a[i]);
		ans.pf(a[i + 1]);
		i += 2;
	}
	for (auto x : ans) cout << x << " ";
}