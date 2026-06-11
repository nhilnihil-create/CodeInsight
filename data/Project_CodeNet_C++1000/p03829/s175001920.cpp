#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int test[1];
int main() {
	long long n, a, b, k, ans = 0; cin >> n >> a >> b;
	for (int h = 0; h < n; h++) {
		cin >> k;
		if (h != 0) {
			if ((k - test[0]) * a >= b) { ans += b; }
			else { ans += (k - test[0]) * a; }
		}
		test[0] = k;
	}
	cout << ans << endl;
	cin >> n;
}