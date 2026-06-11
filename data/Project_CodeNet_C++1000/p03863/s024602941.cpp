#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	string s, ans;
	set<char> chars;

	cin >> s;

	rep(i, s.length()) chars.insert(s[i]);

	if (chars.size() <= 2) ans = "Second";
	else if (s[0] == s[s.length() - 1]) {
		if (s.length() % 2 == 0) ans = "First";
		else ans = "Second";
	}
	else {
		if (s.length() % 2 == 0) ans = "Second";
		else ans = "First";
	}

	cout << ans << endl;

	return 0;
}
