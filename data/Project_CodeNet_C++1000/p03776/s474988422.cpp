#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()

#pragma region 逆元
const int MAX = 10000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k)
{
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
#pragma endregion


int main()
{
	int n, a, b; cin >> n >> a >> b;
	vector<ll> v(n);
	rep(i, 0, n - 1)cin >> v[i];
	sort(all(v), greater<ll>());
	ll aNum;
	int aCnt = 0;
	int waku = 0;
	aNum = v[a - 1];
	rep(i, 0, n - 1)
		if (v[i] == aNum)
		{
			++aCnt;
			if (i < a)++waku;
		}

	double ave = 0;
	rep(i, 0, a - 1)ave += v[i];
	ave /= a;
	printf("%.6f\n", ave);
	if (v[0] == ave)
	{
		int x = min(aCnt, b);
		ll ans = 0;
		rep(i, a, x)
		{
			ll tmp = 1;
			rep(j, 0, i - 1)
			{
				ll y = aCnt - j;
				ll z = 1 + j;
				tmp = tmp * y / z;
			}
			ans += tmp;
		}
		cout << ans << endl;
	}
	else
	{
		ll ans = 1;
		rep(i, 1, waku)
		{
			ll x = aCnt - i + 1;
			ll y = i;
			ans = ans * x / y;
		}
		cout << ans << endl;
	}
}
