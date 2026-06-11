#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

const ll mod = 1000000007;

vector<ll> fact(200000);

ll make_fact()
{
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i < 150000; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	return 0;
}


int main()
{
	make_fact();
	ll N, M;
	cin >> N >> M;
	if (abs(N - M) > 1)
	{
		cout << 0 << endl;
		return 0;
	}
	ll ans = fact[N] * fact[M];
	ans %= mod;
	if (N == M)
		ans *= 2;
	ans %= mod;
	cout << ans << endl;
	return 0;
}