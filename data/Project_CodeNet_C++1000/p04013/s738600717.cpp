#include <iostream>
#include <map>
#define int long long
using namespace std;

int a[55];
map<int, map<int, int> > f;

signed main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= x;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = -250; j <= 250; j++) {
		f[i][j] += f[i - 1][j - a[i]] + f[i - 1][j];
	}
	cout << f[n][0] - 1 << '\n';
}
