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
	string s;
	cin >> n >> s;

	stack<char> b;

	string t;
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == ')')
		{
			if (b.empty())
			{
				t += "(";
			}
			else
			{
				b.pop();
			}
		}
		else
		{
			b.push(s[i]);
		}
	}

	s = t + s;

	t = "";
	while (!b.empty())
	{
		b.pop();
	}

	for (ll i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '(')
		{
			if (b.empty())
			{
				t += ")";
			}
			else
			{
				b.pop();
			}
		}
		else
		{
			b.push(s[i]);
		}
	}

	s = s + t;

	println(s);

}