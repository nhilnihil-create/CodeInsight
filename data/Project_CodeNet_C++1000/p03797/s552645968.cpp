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
	ll s, c;
	cin >> s >> c;

	ll res = 0;

	while (c > 1)
	{
		if (s == 0)
		{
			res += c / 4;
			c = 0;
		}
		else if (2 * s < c)
		{
			res += s;
			c -= 2 * s;
			s = 0;
			
		}
		else
		{
			res += c / 2;
			s -= c / 2;
			c = 0;
			
		}
	}

	println(res);
}