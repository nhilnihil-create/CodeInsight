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
	ll n;
	cin >> n;

	vector<ll> a(n);
	vector<ll> h(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];

			h[a[i]]++;
	}

	bool b = true;
	if (n % 2 == 1)
	{
		for (ll i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (h[i] != 1)
				{
					b = false;
				}
			}
			else if (i % 2 == 0)
			{
				if (h[i] % 2 == 1 || h[i] > 2)
				{
					b = false;
				}
			}
			else
			{
				if (h[i] > 0)
				{
					b = false;
				}
			}
		}

		if (b)
		{
			ull res = 1;
			for (ll i = 0; i < n / 2; i++)
			{
				res = (res * 2) % mod;
			}
			println(res);
		}
		else
		{
			println(0);
		}
	}
	else
	{
		for (ll i = 0; i < n; i++)
		{
			if (i % 2 == 1)
			{
				if (h[i] != 2)
				{
					b = false;
				}
			}
			else
			{
				if (h[i]  > 0)
				{
					b = false;
				}
			}
		}

		if (b)
		{
			ull res = 1;
			for (ll i = 0; i < n / 2; i++)
			{
				res = (res * 2) % mod;
			}
			println(res);
		}
		else
		{
			println(0);
		}
	}
}
