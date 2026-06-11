#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> primeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


#define in(x) cin >> x
#define out(x) cout << x
#define outn(x) cout << x << '\n'
#define outs(x) cout << x << ' '
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
	ll h, w;
	map<char, ll> m;
	std::cin >> h >> w;
	vector<string> a(h);

	rep(i, 0, h) {
		std::cin >> a[i];
		rep(j, 0, w) {
			m[a[i][j]]++;
		}
	}

	ll f = (h / 2) * (w / 2);
	ll t = (w / 2) * (h - 2 * (h / 2)) + (h / 2) * (w - 2 * (w / 2));
	ll o = h * w - 4 * f - 2 * t;

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		ll tmp = min(itr->second / 4, f);
		itr->second -= 4*tmp;
		f-=tmp;

		tmp = min(itr->second / 2, t);
		itr->second -= 2 * tmp;
		t -= tmp;

		if (itr->second == 1 && o == 1) {
			itr->second--;
			o--;
		}

		if (itr->second > 0) {
			outn("No");
			return 0;
		}

	}

	outn("Yes");

	return 0;
}
