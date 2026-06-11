#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


int main()
{
	ll n, m;
	cin >> n >> m;

	vector<pair<ll, bool>> a(n);
	for (ll i = 0; i < n; i++)
	{
		a[i].first = 1;
		a[i].second = false;
	}

	a[0].second = true;

	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;

		x--;
		y--;

		a[y].first++;
		a[x].first--;

		if (a[x].second)
		{
			if (a[x].first == 0)
			{
				a[x].second = false;
			}
			a[y].second = true;
		}
	}

	ll cnt = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i].second)
		{
			cnt++;
		}
	}

	println(cnt);
}
