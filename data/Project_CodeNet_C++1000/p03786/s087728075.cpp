#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P;
#define INF 10000000000000
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
#define repN_1(i, n) for(ll i = 0; i < (ll)(n - 1); i++)
#define repM(i, n) for(ll i = (ll)(n - 1); i >= 0; i--)
#define repM_1(i, n) for(ll i = (ll)(n - 1); i >= 1; i--)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main()
{
	cout << fixed << setprecision(18);

	// 1．最大値の半分の生物までは単独でOK
	// 2. それ未満は足して半分以上にできるかどうか

	ll n;
	cin >> n;
	vector<ll> a(n);
	ll ans = 0;

	rep(i, n)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector<ll> sum(n, 0);

	sum[0] = a[0];
	rep1(i, n)
		sum[i] = sum[i - 1] + a[i];

	repM_1(i, n - 1) {
		if (sum[i - 1] * 2 < a[i]) {
			ans = n - i;
			break;
		}
		if (i == 1)
			ans = n;
	}
	

	cout << ans << endl;

	return 0;
}