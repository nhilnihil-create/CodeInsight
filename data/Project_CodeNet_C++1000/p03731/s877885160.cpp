#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, tt;
	cin >> n >> tt;

	long long ans = 0;
	long long t,tim;
	cin >> t;
	ans = tt;
	tim = tt;
	for (long long i = 2; i <= n; i++) {
		cin >> t;
		if (tim  > t) {
			ans +=  tt - (tim - t);
			tim = t + tt;
		}
		else {
			ans += tt;
			tim = t + tt;
		}


	}
	cout << ans << endl;

}