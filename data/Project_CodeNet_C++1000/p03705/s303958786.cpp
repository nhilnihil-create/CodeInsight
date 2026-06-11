#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

signed main() {
	ll N, A, B; cin >> N >> A >> B;
	if (N == 1) {
		if (A == B)cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if (A > B)cout << 0 << endl;
	else {
		ll ans = (B - A)*(N - 2) + 1;
		cout << ans << endl;
	}
}