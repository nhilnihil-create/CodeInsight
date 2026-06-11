#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N];
long long res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int cur = 1;
	for (int i = 1; i <= n; ++i) {
		int rem = a[i] % cur;
		if (rem == 0) {
			res += a[i] / cur - 1;
			if (a[i] == cur || cur == 1) {
				++cur;
			}
		} else {
			res += a[i] / cur;
		}
	}

	cout << res << endl;
}