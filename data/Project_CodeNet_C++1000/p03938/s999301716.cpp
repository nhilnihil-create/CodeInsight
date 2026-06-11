#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vi p(n), a(n), b(n);
	for (auto& i : p) {
		cin >> i;
		--i;
	}
	
	for (int i = 0; i < n; ++i)
		a[i] = (i + 1) * 3e4;
	
	for (int i = n - 1; i >= 0; --i)
		b[i] = (n - i) * 3e4;
	
	int li = -1, change = 0;
	for (auto i : p) {
		if (li == -1) {
			li = i;
		} else {
			if (i > li) {
				a[i] += ++change;
			} else {
				b[i] += ++change;
			}
		}
	}
	
	for (auto i : a) cout << i << ' ';
	cout << '\n';
	for (auto i : b) cout << i << ' ';
}
