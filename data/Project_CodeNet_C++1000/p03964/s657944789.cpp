#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll> t(n), a(n);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> a[i];
	
	for (int i = 1; i < n; i++) {
		ll fir = t[i - 1] / t[i] + 1;
		ll sec = a[i - 1] / a[i] + 1;
		if (t[i - 1] % t[i] == 0)
			fir--;
		if (a[i - 1] % a[i] == 0)
			sec--;
		ll fact = max(fir, sec);
		t[i] *= fact;
		a[i] *= fact;
	}
	cout << t[n - 1] + a[n - 1] << endl;
	return 0;
}