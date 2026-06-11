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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main()
{
	ll n, c, k, ans;
	cin >> n >> c >> k;
	ans = 0;

	vector<ll> t(n);

	rep(i, n)
		cin >> t[i];

	sort(t.begin(), t.end());

	ll f, r; // f:現在のバスに乗る最初の乗客の到着時間，r:バスに現在何人乗っているか
	f = r = 0;
	rep(i, n)
	{
		r++;
		// バスに乗客がいないとき
		if (f == 0)
		{
			f = t[i];
			ans++;
		}
		// 捌く対象の客が，バスの最初の乗客が乗ってからkより大きい時間たってから到着するとき
		if (t[i] - f > k)
		{
			r = 1;
			f = t[i];
			ans++;
		}
		// バスの定員が埋まったとき
		else if (r == c)
		{
			f = 0;
			r = 0;
		}

	}

	cout << ans << endl;

	return 0;
}