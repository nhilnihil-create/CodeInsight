#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
	int n;
	cin >> n;

	const int MOD = 1e9 + 7;

	ll ans = 1;
	rep(i, n)
	{
		ans *= (i + 1);
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
