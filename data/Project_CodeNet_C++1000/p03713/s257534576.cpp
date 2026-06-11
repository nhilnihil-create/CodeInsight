#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	ll h, w;
	cin >> h >> w;

	ll s = h*w;
	ll res = h*w;
	for (ll i=1; i<=h; i++) {
		ll s1 = i * w;
		ll rh = h - i;
		ll s2;
		if (abs(w*(rh/2) - w*(rh-rh/2)) < abs((w/2)*rh - (w-w/2)*rh)) {
			s2 = w*(rh/2);
		}
		else s2 = (w/2)*rh;
		ll s3 = s - s1 - s2;
		res = min(res, max(max(s1, s2), s3) - min(min(s1, s2), s3));
	}

	for (ll i=1; i<=w; i++) {
		ll s1 = i * h;
		ll rw = w - i;
		ll s2;
		if (abs(h*(rw/2) - h*(rw-rw/2)) < abs((h/2)*rw - (h-h/2)*rw)) {
			s2 = h*(rw/2);
		}
		else s2 = (h/2)*rw;
		ll s3 = s - s1 - s2;
		res = min(res, max(max(s1, s2), s3) - min(min(s1, s2), s3));
	}
	cout << res << endl;
}