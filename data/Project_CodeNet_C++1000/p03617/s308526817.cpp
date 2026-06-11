#include<bits/stdc++.h>
using namespace std;
int main() {
	long long q, h, s, d; cin >> q >> h >> s >> d;
	long long n; cin >> n;

	long long res1, res2;
	res1 = min({q * 4, h * 2, s}) * n;
	res2 = n / 2 * d + min({q * 4, h * 2, s}) * (n % 2);

	cout << min(res1, res2) << endl;
	return 0;
}
