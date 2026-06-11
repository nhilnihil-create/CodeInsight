#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
const long long mod = 1e9 + 7;
ll A[maxn];	//A[i]表示i的阶乘
ll B[maxn];	//B[i]表示i的阶乘关于mod的逆元
using namespace std;

ll pow_mod(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a%mod;
		b >>= 1;
		a = a * a%mod;
	}
	return ret;
}

void Init()
{
	A[0] = 1;
	for (int i = 1; i <= maxn; i++)
		A[i] = (A[i - 1] * i) % mod;
	for (int i = maxn; i >= 0; i--)
		B[i] = pow_mod(A[i], mod - 2);
}

ll C(ll n, ll m) {
	if (n < m)
		return 0;
	return (A[n] * B[m] % mod)*B[n - m] % mod;
}

ll count_ways(ll a, ll b, ll c, ll d) {
	ll tot = (c - a) + (d - b);
	ll down = (c - a);
	ll ret = C(tot, down);
	return ret;
}

int main()
{
	Init();
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	ll tot = count_ways(1, 1, h, w);
	for (ll i = 1; i <= b; i++) {
		ll tmp = count_ways(1, 1, h - a, i)*count_ways(h - a + 1, i, h, w) % mod;
		while (tot < tmp) tot += mod;//防止出现负数
		tot = (tot - tmp) % mod;
	}
	cout << tot;
	return 0;
}