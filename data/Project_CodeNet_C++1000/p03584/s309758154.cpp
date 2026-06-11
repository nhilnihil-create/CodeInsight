#pragma region
#define _USE_MATH_DEFINES
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
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	vector<ll> a(n), b(n);
	rep(i, n)cin >> a[i] >> b[i];
	ll res = 0;
	ll tmp = 0;
	rep(i, n)
	{
		if ((k | a[i]) == k)
		{
			tmp += b[i];
		}
	}
	res = tmp;
	rep(i, 31)
	{
		if (k < 1 << i)break;
		if (!(k&(1 << i)))continue;
		int mask = 0;
		rep(j, i)mask += 1 << j;
		int c = 0;
		rep(j, 31)if (i != j) c += 1 << j;
		c &= k;
		c |= mask;
		tmp = 0;
		rep(i, n)if ((c | a[i]) == c)tmp += b[i];
		res = max(res, tmp);
	}
	cout << res << endl;
}