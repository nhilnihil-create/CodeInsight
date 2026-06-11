#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
 
int n, x;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	if (x == 2 * n - 1 || x == 1) {
		cout << "No";
		return 0;
	} else {
		cout << "Yes\n";
		if (n % 2 && x == n) {
			for (int i = 1; i < 2 * n; ++i) cout << i << '\n';
			return 0;
		}
		vector<int> l, r;
		l.push_back(x - 1); r.push_back(x + 1);
		
		int a[] = {0, 1};
		for (int i = (x + 2) % (2 * n); i != x - 1; i++, i %= (2 * n)) {
			if (!i) {
				++i;
				if (i == x - 1) break;
			}
			if (a[0] != a[1]) {
				if (a[1]) r.push_back(i);
				else l.push_back(i);
				a[0] = a[1];
			} else {
				if (a[1]) l.push_back(i);
				else r.push_back(i);
				a[1] = !a[1];
			}
		}
		
		
		reverse(all(l));
		for (auto i : l) cout << i << '\n';
		cout << x << '\n';
		for (auto i : r) cout << i << '\n';
	}
}
