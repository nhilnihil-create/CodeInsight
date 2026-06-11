#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

ll n, a[MAXN], s;
ll indo = -1;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}

	if (n == 1) {
		cout << "Second\n";
		return 0;
	}

	int ct = 0;
	while (true) {
		indo = -1;
		s = 0;
		for (int i = 0; i < n; ++i)
			s += a[i];
		if (s%2 == (n+1)%2) {
			cout << ((ct%2 == 0) ? "First\n" : "Second\n");
			return 0;
		}

		for (int i = 0; i < n; ++i) {
			if (a[i]%2 == 1) {
				if (indo != -1) {
					cout << ((ct%2 == 0) ? "Second\n" : "First\n");
					return 0;
				}

				indo = i;
			}
		}

		if (a[indo] == 1) {
			cout << ((ct%2 == 0) ? "Second\n" : "First\n");
			return 0;
		}

		a[indo]--;

		ll g = 0;
		for (int i = 0; i < n; ++i)
			g = __gcd(g + a[i], a[i]);
		for (int i = 0; i < n; ++i)
			a[i] /= g;
		++ct;
	}
}