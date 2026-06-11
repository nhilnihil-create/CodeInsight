#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdint>

using namespace std;

typedef long long signed int ll;

ll n, a, b, v[50];

constexpr int bts = 8;
class int256 {
private:
public:
	int32_t d[bts];
	int256(int32_t n) {
		for (int i = 0; i < bts; i++) d[i] = 0;
		d[0] = n;
	}
	int256 operator+(int256 e) {
		int256 r(0);
		for (int i = 0; i < bts; i++) {
			int64_t j = d[i], k = e.d[i];
			if (r.d[i] + j + k > INT32_MAX) {
				r.d[i] += (j + k - INT32_MAX);
				if (i + 1 < bts) r.d[i + 1]++;
			}
			else r.d[i] += j + k;
		}
		return r;
	}
	int256 operator*(int256 e) {
		int256 r(0);
		for (int i = 0; i < bts; i++) for (int j = 0; j < bts; j++) {
			int256 p(0);
			int64_t s = d[i], t = e.d[j];
			int64_t u = s * t;
			if(i + j < bts) p.d[i + j] = u % INT32_MAX;
			if(i + j + 1 < bts) p.d[i + j + 1] = u / INT32_MAX;
			r = r + p;
		}
		return r;
	}
	int64_t to64() {
		int64_t r = d[1];
		r *= INT32_MAX;
		r += d[0];
		return r;
	}
};

int256 fac(long n) {
	int256 r(1);
	for (long i = 1; i <= n; i++) {
		r = (r * int256(i));
	}
	return r;
}
/*
ll comb(ll a, ll b) {
	return fac(a) / (fac(b) * fac(a - b));
}
*/

ll comb(ll a, ll b) {
	if (b == 0) return 1;
	return (comb(a - 1, b - 1) * a) / b;
}

int main() {
	cin >> n >> a >> b;
	for (ll i = 0; i < n; i++) cin >> v[i];
	sort(v, v + n,greater<ll>());
	ll sum = 0;
	for (ll i = 0; i < a; i++) sum += v[i];
	cout << setprecision(20) <<(double)sum / a << endl;
	if (b > a && v[a] * a == sum) {
		ll ci = 0, cj = a;
		while (cj < n && v[cj] == v[a - 1]) cj++;
		while (v[ci] != v[a - 1]) ci++;
		ll r = 0;
		for (ll i = a; i <= min(b, cj); i++)
			r += comb(cj - ci, i - ci);
		cout << r << endl;
	}
	else if (b > a && v[a] == v[a-1]) {
		ll ci = 0, cj = a;
		while (cj < n && v[cj] == v[a - 1]) cj++;
		while (v[ci] != v[a - 1]) ci++;
		ll r = 0; 
		r += comb(cj - ci, a - ci);
		cout << r << endl;
	}
	else cout << 1 << endl;
}