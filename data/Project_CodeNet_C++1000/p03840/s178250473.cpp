#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <complex>
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int main(){
	ll a, b, c, d, e, f, g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	ll t = min({ a,d,e });
	a -= t; d -= t; e -= t;
	ll ans = 3 * t + a / 2 * 2 + b + d / 2 * 2 + e / 2 * 2;
	if (t != 0) {
		t--;
		a++; d++; e++;
		chmax(ans, 3 * t + a / 2 * 2 + b + d / 2 * 2 + e / 2 * 2);
	}
	cout << ans << endl;
}