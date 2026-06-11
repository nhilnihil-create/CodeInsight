#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

ll n, l;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	bool pos = false;
	int index = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i && a[i] + a[i - 1] >= l) {
			pos = true;
			index = i;
		}
	}
	
	if (!pos) {
		cout << "Impossible";
	} else {
		cout << "Possible\n";
		for (int i = 1; i < index; ++i) cout << i << '\n';
		for (int i = n - 1; i > index; --i) cout << i << '\n';
		cout << index;
	}
}
