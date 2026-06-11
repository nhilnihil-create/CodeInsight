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

	set<ll> x;
	vector<pair<ll, ll>> p(m);
	for (ll i = 0; i < m; i++)
	{
		ll a, b;
		cin >> a >> b;

		p[i].first = a;
		p[i].second = b;

		if (a == 1)
		{
			x.insert(b);
		}
	}

	string res = "IMPOSSIBLE";
	for (ll i = 0; i < m; i++)
	{
		if (p[i].second == n)
		{
			if (x.count(p[i].first))
			{
				res = "POSSIBLE";
			}
		}
	}

	println(res);
}
