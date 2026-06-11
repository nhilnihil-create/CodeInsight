#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}	
	int id = -1;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] + a[i + 1] >= l) {
			id = i;
			break;
		}
	}
	if (id == -1) {
		cout << "Impossible\n";
	}
	else {
		cout << "Possible\n";
		for (int i = 0; i < id; i++) {
			cout << i + 1 << '\n';
		}
		for (int i = n - 2; i >= id + 1; i--) {
			cout << i + 1 << '\n';
		}
		cout << id + 1 << '\n';
	}
}	