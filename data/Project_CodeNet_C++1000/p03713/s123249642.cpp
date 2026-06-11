#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;

int main() {

	ll h, w;
	cin >> h >> w;
	
	vector<ll> s(3);
	
	if (h < w) {
		swap(h, w);
	}

	ll ans;
	if (h % 3 == 0 || w % 3 == 0) {
		ans = 0;
	}
	else {
		ll h1 = h / 3;
		if (h % 3 == 2) {
			h1++;
		}

		s[0] = h1 * w;
		ll h2 = h - h1;

		ll w2 = w;
		if (h2 < w2) {
			swap(h2, w2);
		}

		if (h2 % 2 == 0 || w2 % 2 == 0) {
			s[1] = s[2] = h2 * w2 / 2;
		}
		else {
			s[1] = h2 / 2 * w2;
			s[2] = (h2 / 2 + 1)*w2;
		}

		sort(s.begin(), s.end());
		ans = s[2] - s[0];

		if (ans > h / 2 && h%2 == 0) {
			ans = h / 2;
		}
	}

	cout << ans << endl;
}