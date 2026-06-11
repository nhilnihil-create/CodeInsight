#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back

int n, m;
int a[106];
vi b;

auto ifodd = [](int x) { return x % 2 == 1; };
auto ifeven = [](int x) { return x % 2 == 0; };

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	
	int odd = count_if(a, a + m, ifodd);
	if (odd > 2) {
		puts("Impossible");
		return 0;
	}
	
	if (odd == 0) {
		b.pb(1);
		for (int i = 0; i < m - 1; ++i)
			b.pb(a[i]);
		b.pb(1);
		b.pb(a[m - 1] - 2);
		
	} else if (odd == 1) {
		if (m == 1) {
			b.pb(1);
			b.pb(a[0] - 1);
		} else {
			partition(a, a + m, ifodd);
			b.pb(a[0] + 1);
			for (int i = 1; i < m - 1; ++i)
				b.pb(a[i]);
			b.pb(1);
			b.pb(a[m - 1] - 2);
		}
	} else if (odd == 2) {
		partition(a, a + m, ifodd);
		partition(a + 1, a + m, ifeven);
		b.pb(a[0] + 1);
		for (int i = 1; i < m - 1; ++i)
			b.pb(a[i]);
		b.pb(a[m - 1] - 1);
	}
	
	b.erase(remove(b.begin(), b.end(), 0), b.end());
	
	for (int i = 0; i < m; ++i)
		cout << a[i] << ' ';
	cout << endl;
	cout << b.size() << endl;
	for (auto i : b)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}
