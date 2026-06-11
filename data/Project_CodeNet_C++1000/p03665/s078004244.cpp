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

	ll n, p;
	cin >> n >> p;
	
	vector<ll> a(n);
	ll count_o, count_e;
	count_o = count_e = 0;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
			count_e++;
		else
			count_o++;
	}

	if (n == 1)
	{
		if (p == 0 && count_e == 0)
			cout << 0 << endl;
		else if (p == 1 && count_o == 0)
			cout << 0 << endl;
	}
	else
	{
		if (p == 1 && count_o == 0)
			cout << 0 << endl;
		else if(p == 0 && count_o == 0)
			cout << (ll)pow(2, n) << endl;
		else
			cout << (ll)pow(2, n - 1) << endl;
	}

	return 0;
}