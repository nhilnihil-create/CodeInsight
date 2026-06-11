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
	ll a, b, c;
	cin >> a >> b >> c;

	ll res = 0;
	if (a % 2 == 0 && a == b && a == c)
	{
		res = -1;
	}
	else
	{
		while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
		{
			res++;

			ll a0 = a;
			ll b0 = b;
			ll c0 = c;

			a = b0 / 2 + c0 / 2;;
			b = a0 / 2 + c0 / 2;;
			c = b0 / 2 + a0 / 2;;


		}
	}
	println(res);
}