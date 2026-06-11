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

map <int, vector<int> > inf;
vector <int> dat;
vector <int> mx;


int main()
{
	fast;

	int n, t, a, b, c, d, i, j, mxDif = 0, res = 0;

	cin >> n >> t;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		dat.push_back(a);

		inf[a].push_back(i);
	}

	mx.resize(n);
	mx[n - 1] = dat[n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		mx[i] = max(mx[i + 1], dat[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		mxDif = max(mxDif, mx[i + 1] - dat[i]);
	}

	for (auto& it : inf)
	{
		int aa = it.first, bb = it.first + mxDif, tn;
		vector <pii> totalInf;

		if (inf[bb].size() == 0)
		{
			inf.erase(inf.find(bb));

			continue;
		}

		for (auto& itt : it.second)
		{
			totalInf.push_back({ itt, aa });
		}
		for (auto& itt : inf[bb])
		{
			totalInf.push_back({ itt, bb });
		}

		sort(totalInf.begin(), totalInf.end());

		int tr = 0;
		vector <int> pr(totalInf.size()), sf(totalInf.size());

		tn = totalInf.size();

		pr[0] = 0;
		if (totalInf[0].second == aa)
		{
			pr[0]++;
		}
		for (i = 1; i < totalInf.size(); i++)
		{
			pr[i] = pr[i - 1];
			if (totalInf[i].second == aa)
			{
				pr[i]++;
			}
		}

		sf[tn - 1] = 0;
		if (totalInf[tn - 1].second == bb)
		{
			sf[tn - 1]++;
		}
		for (i = tn - 2; i >= 0; i--)
		{
			sf[i] = sf[i + 1];
			if (totalInf[i].second == bb)
			{
				sf[i]++;
			}
		}

		tr = min(pr.back(), sf[0]);
		for (i = 0; i < tn - 1; i++)
		{
			tr = min(tr, pr[i] + sf[i + 1]);
		}

		res += tr;
	}

	cout << res;

	return 0;
}