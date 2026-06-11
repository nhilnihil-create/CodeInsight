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
using ldouble = long double;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;


int main()
{
	ll a[2];
	for (ll i = 0; i < 2; i++)
	{
		int x;
		cin >> x;

		if (x == 2)
		{
			a[i] = 0;
		}
		else if ((x < 8 && x % 2 == 1) || (x >= 8 && x % 2 == 0))
		{
			a[i] = 1;
		}
		else
		{
			a[i] = 2;
		}

	}

	
	if (a[0] == a[1])
	{
		println("Yes");
	}
	else
	{
		println("No");
	}
}