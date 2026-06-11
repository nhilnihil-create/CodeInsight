#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long q, h, s, d, n, ans;

	cin >> q >> h >> s >> d >> n;
	cout << min(n * min(q * 4, min(h * 2, s)), n / 2 * d + (n % 2) * min(q * 4, min(h * 2, s))) << endl;
}
