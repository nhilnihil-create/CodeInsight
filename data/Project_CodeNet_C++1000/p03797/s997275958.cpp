#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	ll ans;
	if (n * 2 > m)
		ans = m / 2;
	else
		ans = n + (m - 2 * n) / 4;
	cout << ans << endl;
	return 0;
}