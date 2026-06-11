#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[1234567], aa[12345678];
signed main() {
	int n, a, b, cnt = 0, zentai = 0, saigo = 0, ans = 0; double sum = 0; cin >> n >> a >> b;
	for (int h = 0; h < n; h++) { cin >> test[h]; }
	sort(test, test + n); reverse(test, test + n);
	for (int h = 0; h < a; h++) { sum += test[h]; }
	sum /= a; printf("%.10f\n", sum); saigo = test[a - 1];
	for (int h = 0; h < n; h++) { if (test[h] == saigo) { zentai++; } }
	for (int h = 0; h < a; h++) { if (test[h] == saigo) { cnt++; } }
	int z = 1;
	for (int h = 1; h <= cnt; h++) {
		z *= zentai - h + 1; z /= h;
	}
	if (sum != test[a - 1]) {
		cout << z << endl; return 0;
	}
	for (int h = a - 1; h < b; h++) {
		cnt++;
		if (test[h] == saigo) {
			ans += z; z *= zentai - cnt + 1; z /= cnt;
			//cout << z << ' ' << ans << endl;
		}
		else { break; }
	}
	cout << ans << endl;
	return 0;
}