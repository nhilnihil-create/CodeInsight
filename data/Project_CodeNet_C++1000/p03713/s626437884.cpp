#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ll h, w, z = 1e10;
	cin >> h >> w;
	if (h % 3 == 0) z = min(z, (ll)0);
	else z = min(z, w);
	if (w % 3 == 0) z = min(z, (ll)0);
	else z = min(z, h);
	for ( int i = 1 ; i < h ; i++ ) {
		ll a = w * i, b, c;
		if (w % 2 == 0) b = (w / 2) * (h - i), c = (w / 2) * (h - i);
		else b = (w / 2) * (h - i), c = (w / 2 + 1) * (h - i);
		z = min(z, max({a, b, c}) - min({a, b, c}));
	}
	for ( int i = 1 ; i < w ; i++ ) {
		ll a = h * i, b, c;
		if (h % 2 == 0) b = (h / 2) * (w - i), c = (h / 2) * (w - i);
		else b = (h / 2) * (w - i), c = (h / 2 + 1) * (w - i);
		z = min(z, max({a, b, c}) - min({a, b, c}));
	}
	cout << z;
}