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

// 最大公約数を求める
template<typename T> T gcd(T a, T b)
{
	return b > 0 ? gcd(b, a % b) : a;
}

// 最小公倍数を求める
template<typename T> T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ll n;
	cin >> n;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll res = 1;
	for (ll i = 0; i < n; i++)
	{
		res = lcm(res, a[i]);
	}

	println(res);
}