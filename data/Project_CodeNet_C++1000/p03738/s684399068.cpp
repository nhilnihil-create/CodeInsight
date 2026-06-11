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
	string a, b;
	cin >> a >> b;

	string a0 = a;
	string b0 = b;

	ll m = max(a.length(), b.length());
	for (ll i = 0; i < m - a.length(); i++)
	{
		a0 = "0" + a0;
	}

	for (ll i = 0; i < m - b.length(); i++)
	{
		b0 = "0" + b0;
	}

	string res = "EQUAL";
	if (a0 > b0)
	{
		res = "GREATER";
	}
	else if (a0 < b0)
	{
		res = "LESS";
	}

	println(res);
}