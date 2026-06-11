#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int a[int(1e6)];
int res;
 
int main() {
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 2 * n + 1);
	for (int i = 1; i <= 2 * n; i += 2) {
		res += a[i];
	}
	cout << res << endl;
}