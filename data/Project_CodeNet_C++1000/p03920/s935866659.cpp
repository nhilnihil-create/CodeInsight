#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#define rep_r(i,s,n)for(ll i=n;i>s;i--)
#define repe_r(i,s,n)for(ll i=n;i>=s;i--)
static const ll MOD = 1e9 + 7;
static const ll MAX_L = (ll)1 << 62;

int main() {
	ll n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	ll k = 0;
	ll m = 0;
	repe(i, 1, n / 2 + 1) {
		ll sum = i * (i + 1) / 2;
		if (n <= sum) {
			k = sum - n;
			m = i;
			break;
		}
	}
	repe(i, 1, m) {
		if (i != k) {
			cout << i << endl;
		}
	}

	return 0;
}