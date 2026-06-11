#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a, b, c, d, ans, i, v[N];
int main() {
	cin >> a >> b >> c >> d;
	for (i = a + 1; i <= b; i++) v[i] = 1;
	for (i = c + 1; i <= d; i++) if (v[i]) ans++;
	cout << ans << endl;
	return 0;
}