#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
#define f(i, l, r) for (int i = l; i <= r; i++)
#define rf(i, r, l) for (int i = r; i >= l; i--)
#define all(x) (x).begin(), (x).end()
#define sf(a) scanf("%d",&a)
#define llsf(a) scanf("%lld", &a)
#define l l
#define r r
#define lch (o << 1)
#define rch (o << 1 | 1)
#define mid ((l + r) >> 1)
#define mem(x, y) memset(x, y, sizeof(x))

const int inf = 2e9 + 7;
const ll INF = INT64_MAX;
double eps = 1e-6;
int mod = 1e9 + 7;
const int N = 1e6 + 10;
const double pi = acos(-1.0);

ll f[N];
ll exgcd(ll a, ll b, ll & x, ll & y) {
	ll c;
	return !b ? (x = 1, y = 0, a) : (c = exgcd(b, a % b, y, x), y -= (a / b) * x, c);
}
ll C(int a,int b) {
	if (a > b)swap(a, b);
	b = a + b - 2; a = a - 1;
	ll x, y; exgcd(f[a] * f[b - a] % mod, mod, x, y); if (x < 0)x += mod;
	return f[b] * x % mod;
}
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	f[0] = 1;
	f(i, 1, 2e5)f[i] = f[i - 1] * i % mod;
	int h, w, a, b; cin >> h >> w >> a >> b;
	ll res = 0;
	f(i, 1, h - a) {
		res = (res + C(i, b + 1) * C(h - i + 1, w - b-1) % mod) % mod;
	}
	res = (res + C(h-a,b+1)*C(a,w-b)%mod) % mod;
	cout << res;
}