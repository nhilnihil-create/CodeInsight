#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll cur = 9;

bool Get(ll x)
{
	if (x == 0) return false;
	cout << "? " << x << endl; fflush(stdout);
	char ch; scanf(" %c", &ch);
	return ch == 'Y';
}

void Answer(ll cur)
{
	cout << "! " << cur << endl; fflush(stdout);
}

int main()
{
	ll bot = 1;
	int cnt = 0;
	while (Get(bot) && cnt <= 10) { cnt++; bot *= 10ll; }
	if (cnt > 10) {
		ll cur = 9;
		ll res = 1;
		while (!Get(cur)) { res *= 10ll; cur = 10ll * cur + 9ll; }
		Answer(res); return 0;
	}
	ll pw = 100000000000ll;
	ll add = 99999999999ll;
	ll res = 0;
	for (int i = 0; i < cnt; i++) {
		int lef = i == 0? 1: 0, rig = 9;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (Get((10ll * res + mid) * pw + add)) rig = mid - 1;
			else lef = mid + 1;
		}
		res = 10ll * res + (rig + 1); pw /= 10ll; add /= 10ll;
	}
	Answer(res);
	return 0;
}