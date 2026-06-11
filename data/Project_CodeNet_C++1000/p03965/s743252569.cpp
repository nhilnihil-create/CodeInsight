#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

int need_g[100001] = { 0 };

int main()
{
	string s;
	int cnt = 0, my_g = 0, point = 0;

	cin >> s;

	rrep(i, s.size()) {
		if (s[i] == 'g') need_g[i] = max(0, need_g[i + 1] - 1);
		else need_g[i] = need_g[i + 1] + 1;
	}
	rep(i, s.size()) need_g[i] = need_g[i + 1];

	rep(i, s.size()) {
		if (my_g == 0) {
			if (s[i] == 'p') point--;
			my_g++;
		}
		else if (s[i] == 'p') {
			if (my_g > 0) my_g--;
			else {
				point--;
				my_g++;
			}
		}
		else if (need_g[i] < my_g) {
			my_g--;
			point++;
		}
		else my_g++;
	}

	cout << point << endl;

	return 0;
}
