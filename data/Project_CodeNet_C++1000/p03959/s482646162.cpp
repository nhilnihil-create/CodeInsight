#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

constexpr int MOD = 1000000007;

// + - * / ^
int mod(int a)
{
	int res = a % MOD;
	if(res < 0) {
		return res + MOD;
	}
	return res;
}
int mul_mod(int a, int b)
{
	ll res = ((ll)a * (ll)b) % MOD;
	return mod((int)res);
}
int pow_mod(int a, int b)
{
	ll res = 1;
	while (b > 0) {
		if(b & 1) {
			res = res * (ll)a % (ll)MOD;
		}
		a = mul_mod(a, a);
		b >>= 1;
	}
	return (int)res;
}
int inv_mod(int a)
{
	return pow_mod(a, MOD - 2);
}
int div_mod(int a, int b)
{
	return mul_mod(a, inv_mod(b));
}

// ! C
constexpr int FAC_MAX = 100000;
ll fac[FAC_MAX], finv[FAC_MAX], inv[FAC_MAX];
void com_init()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < FAC_MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll com_mod(int a, int b){
	if (a < b) return 0;
	if (a < 0 || b < 0) return 0;
	return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> t(n), a(n);
	rep (i, n) cin >> t[i];
	rep (i, n) cin >> a[i];
	vector<bool> amb(n);
	vector<int> h(n);
	bool valid = true;

	// takahashi
	rep (i, n) {
		if (i == 0) {
			amb[0] = false;
		} else {
			amb[i] = (t[i] == t[i - 1]);
		}
		h[i] = t[i];
	}

	// aoki
	reprev (i, n) {
		bool now;
		if (i == n - 1) {
			now = false;
		} else {
			now = (a[i] == a[i + 1]);
		}
		if (now && amb[i]) chmin(h[i], a[i]);
		else if (now) valid &= (a[i] >= h[i]);
		else if (amb[i]) {
			amb[i] = false;
			valid &= (h[i] >= a[i]);
			h[i] = a[i];
		}
		else valid &= (a[i] == h[i]);
	}
	if (!valid) cout << "0\n";
	else {
		ll ans = 1;
		rep (i, n) {
			if (amb[i]) ans = mul_mod(ans, h[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}