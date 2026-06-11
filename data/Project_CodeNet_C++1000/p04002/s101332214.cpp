#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>
#include <random>
#include <memory.h>
#include <bitset>
using namespace std;

#define FILE0
#define MAGIC0
mt19937 rnd(time(0)); //rnd()

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define msl map<string, ll>
#define mls map<ll, string>
#define MOD (1000000007ll)
#define MOD2 (1000000009ll)
#define BIGMOD (1000000000000000007ll)
#define RMOD int(5e8 + rnd() % (int) 5e8)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef FILE1
ifstream in("input.txt");
ofstream out("output.txt");
#endif
#ifdef MAGIC1
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

bool isPrime(ll a)
{
	ll i;
	for (i = 2; i*i <= a; i++)
	{
		if (a%i == 0)
		{
			return 0;
		}
	}
	return (a != 1);
}

bool isPalindrom(const string &s, int l, int r)
{
	for (int i = 0; i < (r - l + 1) / 2; i++)
	{
		if (s[l + i] != s[r - i])
		{
			return 0;
		}
	}
	return 1;
}

template <class type1> type1 gcd(type1 a, type1 b)
{
	type1 t;
	while (b)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

ll positiveMod(ll v, ll md)
{
	v = v%md;
	if (v < 0)
	{
		v += md;
	}
	return v;
}

//-----------------------------------------------------end--------------------------------------//

set <pll> dat;

set <pll> res[10];

int main()
{
	fast;

	ll n, m, k, i, j, a, b, c, kk, x, y;

	cin >> n >> m >> k;

	for (i = 0; i < k; i++)
	{
		cin >> a >> b;

		dat.insert({ a, b });
	}

	for (auto it : dat)
	{
		for (i = max(1ll, it.first - 2); i <= min(n - 2, it.first); i++)
		{
			for (j = max(1ll, it.second - 2); j <= min(m - 2, it.second); j++)
			{
				kk = 0;

				for (x = 0; x < 3; x++)
				{
					for (y = 0; y < 3; y++)
					{
						if (dat.find({ i + x, j + y }) != dat.end())
						{
							kk++;
						}
					}
				}

				res[kk].insert({ i, j });
			}
		}
	}

	ll res0 = (n - 2)*(m - 2);

	for (i = 1; i < 10; i++)
	{
		res0 -= res[i].size();
	}
	
	cout << res0 << "\n";
	for (i = 1; i < 10; i++)
	{
		cout << res[i].size() << "\n";
	}

	return 0;
}