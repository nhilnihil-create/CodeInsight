#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 101234, S = 30000;
int a[MN], n;

bool val(int x, int y) {
//	cout << x << ' ' << y << ' ' << (x < n) << (a[x] > y) << endl;
	return x < n && a[x] > y;
}

bool get(int x, int y) {
//	cerr << x << '|' << y << endl;
	if (val(x + S, y + S))
		return get(x + S, y + S);
	if (val(x + 1, y + 1))
		return get(x + 1, y + 1);
	if (val(x + 1, y) && !val(x, y + 1))
		return !get(x + 1, y);
	if (val(x, y + S) && !val(x + 1, y))
		return get(x, y + S);
	if (val(x, y + 1) && !val(x + 1, y))
		return !get(x, y + 1);
	if (val(x, y + 1)) {
		bool xx = !get(x, y + 1);
		bool yy = !get(x + 1, y);
//		cout << xx << '&' << yy << endl;
		return !get(x, y + 1) | !get(x + 1, y);
	}
//	cerr << "Hora" << endl;
	return false;
}	

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int gd = 0;
	cout << (get(0, 0)? "First": "Second");
}
