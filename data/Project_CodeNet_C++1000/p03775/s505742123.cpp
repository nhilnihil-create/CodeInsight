#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
map<int, int> mp;
void prime_factorize(ll n, vector<ll> &ret)
{
	if (n <= 1)	return;
	ll last = sqrt(n);
	for (ll i = 2; i <= last; i++) {
		if (n % i == 0) {
			prime_factorize(i, ret);
			prime_factorize(n / i, ret);
			return;
		}
	}
	ret.push_back(n);
	return;
}
int getDig(ll i)
{
	int dig = 0;
	while (i != 0) {
		i /= ll(10);
		dig++;
	}
	return dig;
}
int main()
{
	ll n;
	cin >> n;
	vector<ll> fac;
	prime_factorize(n, fac);
	int s = fac.size();
	ll fac1, fac2;
	fac1 = fac2 = 1;
	int ans, dig;
	ans = iINF;
	rep(i, 1 << s) {
		fac1 = fac2 = 1;
		rep(j, s) {
			if (i >> j & 1)	fac1 *= fac[j];
			else fac2 *= fac[j];
		}
		dig = max(getDig(fac1), getDig(fac2));
		ans = min(ans, dig);
	}
	cout << ans << endl;
	return 0;
}
