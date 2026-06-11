#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mods = 1E9 + 7;
int frac[200500] = {1}, ifac[200500];
signed main()
{
	int n = 0, m = 0, a = 0, b = 0;
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= 200000; i++) frac[i] = frac[i - 1] * i % mods;
	ifac[200000] = 1; for(int i = frac[200000]; i > 1; i = mods % i) ifac[200000] = ifac[200000] * (mods - mods / i) % mods;
	for(int i = 200000; i; i--) ifac[i - 1] = ifac[i] * i % mods;
	#define C(a,b) (frac[(a)+(b)]*ifac[a]%mods*ifac[b]%mods)
	int ans = C(n - 1, m - 1);
	for(int i = 1; i <= b; i++)
		ans = (ans + mods - C(n - a - 1, i - 1) * C(a - 1, m - i) % mods) % mods;
	cout << ans << endl;
	return 0;
}