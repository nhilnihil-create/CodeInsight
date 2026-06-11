#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main(){
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, 0, n) {
		cin >> a[i]; sum += a[i];
	}
	if (sum % (1LL * n * (n + 1) / 2)) {
		printf("NO"); return 0;
	}
	sum /= (1LL * n * (n + 1) / 2);
	rep(i, 0, n) {
		ll d = a[i] - a[(i - 1 + n) % n];
		if (sum - d < 0 || (sum - d) % n != 0) {
			printf("NO"); return 0;
		}
	}
	printf("YES");
	return 0;
}
