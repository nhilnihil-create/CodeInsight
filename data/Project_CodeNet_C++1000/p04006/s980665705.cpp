#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define int long long
#define mod 1000000007
using namespace std;
int a[2345][2345], n, x, ans, cnt;
signed main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		ans += a[i][0];
	}
	for (int j = 1; j <= n; j++) {
		cnt = x * j;
		for (int i = 1; i <= n; i++) {
			int p = i - j; if (p <= 0)p += n;
			a[i][j] = min(a[i][j - 1], a[p][0]);
			cnt += a[i][j];
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}