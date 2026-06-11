#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)

using ll = long long;
using namespace std;
 
int main() {
	ll a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	n *= 4;
	b = min(b, a + a);
	c = min(c, b + b);
	d = min(d, c + c);
	ll res = 0;
	if (n & 1) {
		n -= 1;
		res += a;
	}
	if (n & 2) {
		n -= 2;
		res += b;
	}
	if (n & 4) {
		n -= 4;
		res += c;
	}
	res += d * (n / 8);
	cout << res << endl;
	
	return 0;
}
