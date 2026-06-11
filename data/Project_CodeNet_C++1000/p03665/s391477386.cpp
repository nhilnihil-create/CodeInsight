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
	ll n, p;
	cin >> n >> p;

	vector<ll> a(n);
	ll even = 0;
	ll odd = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}

	ull res = 1;
	if (p == 0)
	{
		for (ll i = 0; i < even; i++)
		{
			res *= 2;
		}

		for (ll i = 0; i < odd - 1; i++)
		{
			res *= 2;
		}
	}
	else
	{
		if (odd == 0)
		{
			res = 0;
		}
		for (ll i = 0; i < even; i++)
		{
			res *= 2;
		}

		for (ll i = 0; i < odd - 1; i++)
		{
			res *= 2;
		}
	}

	println(res);
}
