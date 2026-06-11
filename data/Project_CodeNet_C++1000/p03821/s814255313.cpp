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
	vector<ll> b(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}

	ull cnt = 0;
	ull add = 0;
	for (ll i = n - 1; i >= 0; i--)
	{
		ll o = cnt;
		a[i] += cnt;

		if (b[i] > 1 && a[i] % b[i] > 0)
		{


			cnt += b[i] - (a[i] % b[i]);
		}
	}

	println(cnt);
}
