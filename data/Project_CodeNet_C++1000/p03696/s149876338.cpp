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
	string s;
	ll n;
	
	cin >> n >> s;

	ll count_l = 0;
	ll count_r = 0;

	rep(i, n) {
		if (s[i] == ')') {
			if (count_r == 0)
				count_l++;
			else
				count_r--;
		}
		else if (s[i] == '(') {
			count_r++;
		}
	}

	rep(i, count_l)
		cout << '(';

	cout << s;

	rep(i, count_r)
		cout << ')';

	cout << endl;


	return 0;
}