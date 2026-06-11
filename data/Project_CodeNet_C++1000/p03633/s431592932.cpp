#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return abs(a); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	ll n;
	cin >> n;
	vector<ll> vs(n);
	rep(i, n) cin >> vs[i];
	ll ans = 1;
	rep(i, n) {
		ans = lcm(ans, vs[i]);
	}
	cout << ans << endl;
	return 0;
}
