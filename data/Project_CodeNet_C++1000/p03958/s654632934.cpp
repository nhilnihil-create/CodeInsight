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
	cout << fixed << setprecision(18);

	ll k, t;
	cin >> k >> t;

	vector<P> a(t);
	rep(i, t) {
		ll tmp;
		cin >> tmp;
		a[i] = P(tmp, i);
	}

	sort(a.begin(), a.end(), greater<>());

	ll b = INF;
	ll ans = 0;
	rep(i, k) {
		if (b == a[0].second){
			if (a.size() > 1) {
				a[1].first--;
				b = a[1].second;
				if (a[1].first == 0)
					a.erase(a.begin() + 1);
			}
			else {
				a[0].first--;
				ans++;
			}
		}
		else {
			a[0].first--;
			b = a[0].second;
			if (a[0].first == 0)
				a.erase(a.begin());
		}
		sort(a.begin(), a.end(), greater<>());
	}

	cout << ans << endl;

	return 0;
}