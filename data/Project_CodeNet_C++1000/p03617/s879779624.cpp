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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll n;
	cin >> n;

	ll a0 = 4 * a;
	ll b0 = 2 * b;
	ll c0 = c;

	ll p = min({a0, b0, c0});

	ull res = 0;
	
	if (n % 2 == 0)
	{
		res = min(d, p * 2) * (n / 2);
	}
	else
	{
		res = min(d, p * 2) * (n / 2);
		res += p;
	}

	println(res);
}
