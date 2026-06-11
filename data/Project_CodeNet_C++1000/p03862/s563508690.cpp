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
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC048-C, 1128, 
	int n, x; cin >> n >> x;
	vector<ll> v(n), s(n - 1);
	rep(i, n) {
		cin >> v[i];
		if (i != 0) s[i - 1] = v[i - 1] + v[i];
	}
	ll ans = 0;
	if (v[0] > x) {
		ans += v[0] - x;
		s[0] -= v[0] - x;
	}
	rep(i, n - 1) {
		if (s[i] > x) {
			ans += ll(s[i] - x);
			if (i != n - 2) {
				s[i + 1] -= s[i] - x;
			}
		}
	}
	cout << ans << endl;


	return 0;
}
