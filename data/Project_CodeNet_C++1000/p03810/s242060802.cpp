#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
int cnt;
int a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1) return printf("Second\n"), 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int winner = 0;
	while(true) {
		bool check = true;
		for (int i = 1; i <= n; ++i) if (a[i] != 1) check = false;
		if (check) {
			return printf(winner == 1 ? "First\n" : "Second\n"), 0;
		}

		winner ^= 1;

		int nEven = 0;
		for (int i = 1; i <= n; ++i) if (a[i] % 2 == 0) ++nEven;
		if (nEven % 2 == 1) {
			return printf(winner == 1 ? "First\n" : "Second\n"), 0;
		}

		int pos, nOdd = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > 1 && (a[i] & 1)) nOdd++, pos = i; 
		}
		if (nOdd != 1) {
			return printf(winner == 1 ? "Second\n" : "First\n"), 0;
		}
		a[pos]--;
		int g = 0;
		for (int i = 1; i <= n; ++i) g = __gcd(g, a[i]);
		for (int i = 1; i <= n; ++i) a[i] /= g;
	}
}