#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> cnt(n+1,0);
	rep(i,n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	bool narabi = true;
	if (n%2) {
		if (cnt[0] != 1) narabi = false;
		for (int i=1;i<=n/2;i++) {
			if (cnt[2*i] != 2) narabi = false;
			if (cnt[2*i+1] != 0) narabi = false;
		}
	}
	else {
		for (int i=0;i<=n/2-1;i++) {
			if (cnt[2*i] != 0) narabi = false;
			if (cnt[2*i+1] != 2) narabi = false;
		}
	}
	ll ans = 1;
	ll m = 1e9+7;
	rep(i,n/2) ans = (ans * 2) % m;
	if (!narabi) ans = 0;
	cout << ans << endl;
	return 0;
}
