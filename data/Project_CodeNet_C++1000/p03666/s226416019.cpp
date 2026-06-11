#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

static const ll INF = 1e15;

ll n, k, c;
string s;

int main(void)
{
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	bool ok = false;
	rep(i, n) {
		ll s1 = a - i * c;
		ll s2 = a - i * d;
		ll low = s2 + (n - 1 - i) * c;
		ll up = s1 + (n - 1 - i) * d;
		if (b >= low && b <= up) {
			ok = true;
			break;
		}
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
