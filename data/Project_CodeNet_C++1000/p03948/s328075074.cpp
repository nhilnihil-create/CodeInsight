#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, t, a[114514], ans = 0, min, p = 0;
	cin >> n >> t; for (int i = 0; i < n; i++)cin >> a[i];
	min = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i])min = a[i];
		else if (a[i] - min == p)ans++;
		else if (a[i] - min > p) {
			p = a[i] - min; ans = 1;
		}
	}
	cout << ans << endl;
	return 0;
}