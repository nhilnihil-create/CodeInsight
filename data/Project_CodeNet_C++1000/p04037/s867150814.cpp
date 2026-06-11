#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int n, a[100009], s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		if (i <= a[i])s = i;
	}
	int G1 = a[s] + s, G2 = 0;
	if (s != n) {
		for (int i = s; i <= n; i++) {
			if (a[i] == s)G2 = (i + a[i]);
		}
	}
	if (G1 % 2 == 1 || G2 % 2 == 1) { cout << "First" << endl; }
	else { cout << "Second" << endl; }
	return 0;
}