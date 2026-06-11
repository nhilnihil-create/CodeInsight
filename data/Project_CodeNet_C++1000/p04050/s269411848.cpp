#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
#define pb(x) push_back(x)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>

const int N = 1e5 + 7;

int n, m, a[N];

int main() {
	makefast;
	cin >> n >> m;
	int cf = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1)
			cf++;
	}
	if (n % 2 && cf > 1) {
		cout << "Impossible";
		return 0;
	}
	if (n % 2 == 0 && cf > 2) {
		cout << "Impossible";
		return 0;
	}
	vector <int> v;
	if (n % 2 == 0 && cf == 0) {
		if (a[1] % 4 == 2) {
			if (a[1] / 2 - 1)
				v.pb(a[1] / 2 - 1);
			v.pb(1);
			if (a[1] / 2 - 1)
				v.pb(a[1] / 2 - 1);
		}
		else {
			if (a[1] - 2)
				v.pb(a[1] - 2);
			v.pb(1);
		}
		for (int i = 2; i <= m; i++) {
			if (a[i] % 4 == 2) {
				v.pb(a[i] / 2 + 1);
				if (a[i] / 2 - 1)
					v.pb(a[i] / 2 - 1);
			}
			else {
				v.pb(a[i]);
			}
		}
		v.pb(1);
		for (int i = 1; i <= m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		cout << v.size() << '\n';
		for (auto x: v)
			cout << x << ' ';
		return 0;
	}
	if (n % 2 == 0 && cf == 2) {
		int f1 = 0, f2 = 0;
		for (int i = 1; i <= m; i++)
			if (a[i] % 2 == 1)
				if (!f1)
					f1 = a[i];
				else
					f2 = a[i];
		for (int i = 2; i < f1; i += 2)
			v.pb(2);
		for (int i = 1; i <= m; i++)
			if (a[i] % 4 == 2) {
				v.pb(a[i] / 2 + 1);
				if (a[i] / 2 - 1)
					v.pb(a[i] / 2 - 1);
			}
			else if (a[i] % 4 == 0) 
				v.pb(a[i]);
		for (int i = 2; i <= f2 + 1; i += 2)
			v.pb(2);
		cout << f1 << ' ';
		for (int i = 1; i <= m; i++)
			if (a[i] % 2 == 0)
				cout << a[i] << ' ';
		cout << f2 << '\n';
		cout << v.size() << '\n';
		for (auto x: v)
			cout << x << ' ';
		return 0;
	}
	if (n % 2 == 1 && cf == 1) {
		int f = 0;
		for (int i = 1; i <= m; i++)
			if (a[i] % 2)
				f = a[i];
		for (int i = 2; i < f; i += 2)
			v.pb(2);
		for (int i = 1; i <= m; i++)
			if (a[i] % 4 == 2) {
				v.pb(a[i] / 2 + 1);
				if (a[i] / 2 - 1)
				v.pb(a[i] / 2 - 1);
			}
			else if (a[i] % 4 == 0)
				v.pb(a[i]);
		v.pb(1);
		cout << f << ' ';
		for (int i = 1; i <= m; i++)
			if (a[i] % 2 == 0)
				cout << a[i] << ' ';
		cout << '\n' << v.size() << '\n';
		for (auto x : v)
		cout << x << ' ';
		return 0;
	}
	cout << 1 / 0;
		

}
