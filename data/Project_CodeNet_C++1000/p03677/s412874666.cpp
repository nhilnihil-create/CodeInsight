#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

const ll mod = 1000000007;
const ll INF = 100000000000010000;

ll kai[100010];
ll bit[700010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

/*ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= 700005)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1) {
		return x * pow_mod(x, y - 1) % mod;
	}
	else {
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

ll com(ll x, ll y) {
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
}

ll n, m;
ll a[100010];
ll sum[100010];
ll ans, cir, res;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		ll S = a[i], G = a[i + 1];
		if (S > G) {
			if (G + m - S < 2) continue;
			sum[1] += m - S;
			sum[2] += 1 + S - m;
			sum[G + 1] -= m + G - S;
			sum[G + 2] += m + G - S - 1;
		}
		else {
			sum[G + 1] -= G - S;
			sum[G + 2] += G - S - 1;
		}
		if (a[i] <= m - 2) sum[S + 2]++;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) cir++;
	}
	ans += a[n] + cir * m - a[1];
	rep(i, 2) {
		for (int j = 1; j < m; j++) {
			sum[j + 1] += sum[j];
		}
	}
	res = INF;
	for (int i = 1; i <= m; i++) {
		res = min(ans - sum[i], res);
	}
	cout << res << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}
////////////////////////////////////////////////////////////////////////////////////////////jagfhaoi;sd;joi;asdfjzasdi;lfjoi;ernjsdoivcnoizvdfnvdfnon/////////////////////////////////////////////////////////
////////////////////jgoiadhsjgoi;vsjvgfonhjasoivhoivhno