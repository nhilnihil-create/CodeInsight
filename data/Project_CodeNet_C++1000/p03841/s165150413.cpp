#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;
int x[510];
int a[510 * 510];
int fl[510 * 510];
int nd[510];
set<pair<int, int>> ss;
multiset<int> sfr;

void ex() {
	cout << "No\n";
	exit(0);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", x + i);
		--x[i];
		fl[x[i]] = 1;
		a[x[i]] = i;
	}
	for (int i = 0; i < n; ++i)
		nd[i] = n - i - 1;
	for (int i = 0; i < n; ++i)
		ss.insert(make_pair(-x[i], i));
	for (int i = n * n - 1; i >= 0; --i) {
		if (fl[i]) {
			int x = a[i];
			if (nd[x])
				ex();
			for (int j = 0; j < x; ++j)
				sfr.insert(x);
		}
		else {
			while (!ss.empty()) {
				int x = ss.begin()->second;
				if (!nd[x]) {
					ss.erase(ss.begin());
					continue;
				}
				else {
					--nd[x];
					a[i] = x;
					break;
				}
			}
			if (ss.empty()) {
				if (sfr.empty())
					ex();
				a[i] = *sfr.begin();
				sfr.erase(sfr.begin());
			}
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n * n; ++i)
		printf("%d ", a[i] + 1);
	printf("\n");
	return 0;
}


