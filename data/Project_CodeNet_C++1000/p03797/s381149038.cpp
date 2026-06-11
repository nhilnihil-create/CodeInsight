#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> m;

	long long tmp = min(n, m/2);
	n -= tmp;
	m -= 2*tmp;
	ans += tmp;

	cout << ans + m / 4 << '\n';
	
	return 0;
}