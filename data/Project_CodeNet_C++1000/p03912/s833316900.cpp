#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll mod = 998244353;
const ll INF = 1000000000000000;
ll N, M, ans, x[100010], amari[100010];
ll mp[100010], kumi[100010];

ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll pow_ll(ll x, ll y)
{
	if (y == 0) return 1;
	return x * pow_ll(x, y - 1);
}

ll div(ll x)
{
	return pow(x, mod - 2);
}



int main(void)
{
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
		mp[x[i]]++;
	}
	
	for (int i = 0; i < 100005; i++)
	{
		kumi[i % M] += mp[i] / 2;

		amari[i % M] += mp[i];
	}
	
	for (int i = 1; i <= M / 2; i++)
	{
		if (M % 2 == 0 && i == M / 2)
		{
			ans += amari[i] / 2;
		}
		else
		{
			ll u = min(amari[i], amari[M - i]);
			ans += u;
			ans += (kumi[i] * 2 + u > amari[i] ? (amari[i] - u) / 2 : kumi[i]);
			ans += (kumi[M - i] * 2 + u > amari[M - i] ? (amari[M - i] - u) / 2 : kumi[M - i]);
		}
	}

	ans += amari[0] / 2;

	cout << ans << endl;

	int xxx;
	cin >> xxx;
}
