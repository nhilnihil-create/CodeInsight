#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x, y) (lower_bound(vec.begin(), vec.end(), make_pair(x, y)) - vec.begin())
#define lc (v * 2)
#define rc (v * 2 + 1)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>

#define int long long

const int N = 1e5 + 7;

int a[N];

int32_t main() {
	makefast;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << "Second";
		return 0;
	}
	int t = 1;
	while (1) {
		int odd = 0, eve = 0, one = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2)
				odd++;
			else
				eve++;
			if (a[i] == 1)
				one = 1;
		}
		if (one) {
			if ((odd % 2 != n % 2 && t == 1) || (odd % 2 == n % 2 && t == 2))
			   cout << "First";
			else
			cout << "Second";
		return 0;	
		}
		if (odd % 2 != n % 2) {
			if (t == 1)
				cout << "First";
			else
				cout << "Second";
			return 0;
		}
		if (odd != 1) {
			if (t == 2)
				cout << "First";
			else
				cout << "Second";
			return 0;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] % 2)
				a[i]--;
		int g = a[1];
		for (int i = 2; i <= n; i++)
			g = __gcd(a[i], g);
		for (int i = 1; i <= n; i++) {
			a[i] /= g;
		}
		t = 3 - t;
	}

}